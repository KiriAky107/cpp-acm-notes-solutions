"""由完整笔记和题解生成 GitHub Pages 静态站点；不改写正文。"""
from __future__ import annotations

import hashlib
import html
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import urllib.request
from urllib.parse import unquote, urlparse

from bs4 import BeautifulSoup
from pypdf import PdfReader

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT/'docs'
SOURCE = ROOT/'notes/C艹学习笔记v5.0.md'
PDF = ROOT/'notes/C艹学习笔记v5.0-页码版.pdf'
PDF_PAGES = len(PdfReader(PDF).pages)
GITHUB = 'https://github.com/KiriAky107/cpp-acm-notes-solutions'
SITE = 'https://kiriaky107.github.io/cpp-acm-notes-solutions/'
PANDOC = os.environ.get('PANDOC') or shutil.which('pandoc')
if not PANDOC and Path('C:/Program Files/Pandoc/pandoc.exe').exists():
    PANDOC = 'C:/Program Files/Pandoc/pandoc.exe'
if not PANDOC:
    raise SystemExit('请安装 Pandoc，或通过 PANDOC 环境变量指定其路径。')

def escaped(value):
    return html.escape(str(value), quote=True)

def relative(path, depth):
    return '../'*depth + str(path)

def split_note(text):
    """以二、三级标题划分阅读页，保留各标题下的全部原文。"""
    groups, pages = [], []
    current = None
    fence = None
    for line in text.splitlines(keepends=True):
        marker = re.match(r'^\s*(`{3,}|~{3,})',line)
        if marker:
            if fence is None:
                fence = marker.group(1)[0]
            elif marker.group(1)[0] == fence:
                fence = None
        match = re.match(r'^(#{2,3}) (.+?)\s*$',line) if fence is None else None
        if match:
            level, title = len(match.group(1)),match.group(2)
            if level == 2:
                group = {'title':title,'number':len(groups),'pages':[]}
                groups.append(group)
                slug = f'part-{len(groups)-1:02d}'
            else:
                group = groups[-1]
                slug = f"part-{group['number']:02d}-{len(group['pages']):02d}"
            current = {'title':title,'group':group['number'],'url':f'chapters/{slug}.html',
                       'markdown':'','overview':level==2,'kind':'chapter'}
            pages.append(current)
            group['pages'].append(current)
        if current is not None:
            current['markdown'] += line
    return groups,pages

def convert(markdown):
    result = subprocess.run([PANDOC,'--from=markdown+tex_math_dollars+fenced_code_blocks',
        '--to=html5','--mathjax','--highlight-style=pygments','--wrap=none'],
        input=markdown,capture_output=True,text=True,encoding='utf-8',check=True)
    return BeautifulSoup(result.stdout,'html.parser')

def prepare_page(page, source, heading_counter):
    soup = convert(page['markdown'])
    headings = soup.find_all(re.compile('^h[1-6]$'))
    old_ids = {}
    for heading in headings:
        original = heading.get('id')
        new_id = f"n-{heading_counter[0]:04d}" if page['kind']=='chapter' else f"a-{len(old_ids):02d}"
        heading_counter[0] += page['kind']=='chapter'
        if original:
            old_ids[original] = new_id
        heading['id'] = new_id
    for link in soup.select('a[href^="#"]'):
        target = link['href'][1:]
        if target in old_ids:
            link['href'] = '#'+old_ids[target]
    for pre in soup.find_all('pre'):
        original = pre.get_text()
        for link in pre.find_all('a'):
            link.unwrap()
        if 'sourceCode' in pre.get('class',[]):
            code = pre.find('code',recursive=False)
            if code:
                for number,line in enumerate(code.find_all('span',recursive=False),1):
                    line['data-line'] = str(number)
                    line.attrs.pop('id',None)
        pre.attrs.pop('id',None)
        if pre.parent.name=='div' and 'sourceCode' in pre.parent.get('class',[]):
            pre.parent.attrs.pop('id',None)
        assert pre.get_text()==original
        code = pre.find('code')
        if code and ('mermaid' in code.get('class',[]) or 'mermaid' in pre.get('class',[])):
            diagram = soup.new_tag('div',attrs={'class':'mermaid'})
            diagram.string = code.get_text()
            pre.replace_with(diagram)
    for image in soup.find_all('img'):
        target = (source.parent/unquote(image['src'])).resolve()
        assert target.exists(),target
        if target.is_relative_to(ROOT/'notes/C艹学习笔记.assets'):
            target_url = 'media/notes/'+target.name
        elif target.is_relative_to(ROOT/'assets'):
            target_url = 'media/solutions/'+target.name
        else:
            raise ValueError(f'未识别的插图路径：{target}')
        image['src'] = '../'+target_url
        image['loading'] = 'lazy'
        image['decoding'] = 'async'
    for link in soup.find_all('a',href=True):
        href = link['href']
        parsed = urlparse(href)
        if href.startswith('#') or parsed.scheme in ['mailto','tel']:
            continue
        if parsed.scheme in ['http','https']:
            link['rel'] = 'noopener noreferrer'
            continue
        target = (source.parent/unquote(parsed.path)).resolve()
        if target in source_to_page:
            link['href'] = '../'+source_to_page[target]
        elif target.is_relative_to(ROOT/'code'):
            link['href'] = GITHUB+'/blob/main/'+target.relative_to(ROOT).as_posix()
        elif target.is_relative_to(ROOT):
            link['href'] = GITHUB+'/blob/main/'+target.relative_to(ROOT).as_posix()
        else:
            raise ValueError(f'未识别的正文链接：{href}')
    page['headings'] = [{'id':heading['id'],'title':heading.get_text(),'level':int(heading.name[1])} for heading in headings]
    page['soup'] = soup
    return soup

def sidebar(groups, page, depth):
    parts = ['<nav class="sidebar" id="chapter-nav" aria-label="笔记目录"><p class="sidebar-title">阅读目录</p>']
    for group in groups:
        opened = page.get('group')==group['number'] and page['kind']=='chapter'
        parts.append(f'<details{" open" if opened else ""}><summary>{escaped(group["title"])}</summary>')
        for child in group['pages']:
            active = page['url']==child['url']
            cls = 'current' if active else ''
            if child['overview']:
                cls += ' overview-link'
            name = '本部分导读' if child['overview'] else child['title']
            parts.append(f'<a class="{cls.strip()}" href="{relative(child["url"],depth)}" {"aria-current=page" if active else ""}>{escaped(name)}</a>')
        parts.append('</details>')
    parts.append(f'<a href="{relative("answers/index.html",depth)}">练习题解 · 111 份</a></nav>')
    return ''.join(parts)

def dialogs():
    return '''<dialog id="search-dialog" aria-label="搜索笔记与题解"><div class="search-header"><input type="search" placeholder="搜索主题、接口或题号…" aria-label="搜索关键词" autocomplete="off"><button type="button" aria-label="关闭搜索">Esc</button></div><p class="search-help">查阅笔记正文与全部题解 · Ctrl / ⌘ K</p><div class="search-results" aria-live="polite"></div></dialog><dialog class="image-dialog" id="image-dialog" aria-label="放大过程图"><button type="button">关闭</button><img alt=""></dialog>'''

def shell(page, content, depth=1, reader=True):
    root = '../'*depth or './'
    section = groups[page['group']]['title'] if page['kind']=='chapter' else '练习题解'
    body = content
    if reader:
        toc = ''.join(f'<a class="level-{h["level"]}" href="#{h["id"]}">{escaped(h["title"])}</a>' for h in page.get('headings',[])[1:])
        toc = f'<aside class="page-toc" aria-label="本页目录"><p>本页内容</p>{toc}</aside>' if toc else ''
        breadcrumb = f'<div class="breadcrumb"><a href="{root}index.html">首页</a> / {escaped(section)}</div>'
        source_url = GITHUB+'/blob/main/'+page.get('source','notes/C艹学习笔记v5.0.md')
        meta = f'<div class="article-meta"><span>笔记 v5.0</span><a href="{source_url}">查看 Markdown</a><span>图解可点击放大 · 代码可复制</span></div>'
        body = sidebar(groups,page,depth)+f'<div class="reading-layout"><main id="main" class="article">{breadcrumb}{meta}<article>{body}</article>{navigation(page,depth)}{footer(depth)}</main>{toc}</div>'
        body = f'<div class="page-layout">{body}</div><div class="mobile-backdrop"></div>'
    title = 'C++ / ACM 自学笔记' if page['kind']=='home' else page['title']+' · C++ / ACM 自学笔记'
    nav_active = 'chapter' if page['kind']=='chapter' else 'answer' if page['kind'] in ['answer','answers'] else 'home'
    nav = ''.join(f'<a href="{root}{url}" class="{"active" if key==nav_active else ""}">{label}</a>' for key,url,label in [
        ('home','index.html','首页'),('chapter','chapters/part-00.html','完整笔记'),('answer','answers/index.html','练习题解')])
    vendors = ''
    if 'class="math' in content:
        vendors += f'<script>window.MathJax={{tex:{{inlineMath:[["$","$"],["\\\\(","\\\\)"]]}},svg:{{fontCache:"global"}},startup:{{typeset:false}}}};</script><script defer src="{root}static/vendor/tex-svg.js"></script>'
    if 'class="mermaid"' in content:
        vendors += f'<script defer src="{root}static/vendor/mermaid.min.js"></script>'
    return f'''<!doctype html>
<html lang="zh-CN"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><meta name="description" content="从 C++ 基础、题意建模到搜索、动态规划与图论，配逐步推导、过程图与 111 份带注释题解。"><title>{escaped(title)}</title><link rel="canonical" href="{SITE}{page['url']}"><link rel="icon" href="{root}static/favicon.svg" type="image/svg+xml"><link rel="stylesheet" href="{root}static/site.css"><script>try{{document.documentElement.dataset.theme=localStorage.getItem('cpp-notes-theme')||'light'}}catch{{}}</script>{vendors}<script defer src="{root}static/site.js"></script></head>
<body data-site-root="{root}" data-page-url="{escaped(page['url'])}" data-page-title="{escaped(page['title'])}" data-page-kind="{page['kind']}"><a class="skip" href="#main">跳到正文</a><header class="topbar"><a class="brand" href="{root}index.html">C++ / ACM <small>自学笔记 · v5.0</small></a><nav class="topnav" aria-label="主导航">{nav}<a href="{GITHUB}">GitHub ↗</a></nav><div class="top-actions"><button class="search-open" data-search-open type="button">搜索<kbd>⌘ K</kbd></button><button class="icon-button" type="button" data-theme-toggle aria-label="切换深浅主题">深色</button>{'<button class="icon-button menu-toggle" type="button" aria-controls="chapter-nav" aria-expanded="false">目录</button>' if reader else ''}</div></header>{body}{dialogs()}</body></html>'''

def navigation(page, depth):
    if page['kind']!='chapter':
        return f'<div class="next-prev"><a href="{relative("answers/index.html",depth)}"><small>练习题解</small>返回题号索引</a><a href="{relative("chapters/part-00.html",depth)}"><small>完整笔记</small>回到学习路线</a></div>'
    index = pages.index(page)
    before = pages[index-1] if index else None
    after = pages[index+1] if index<len(pages)-1 else None
    left = f'<a href="{relative(before["url"],depth)}"><small>上一节</small>{escaped(before["title"])}</a>' if before else '<span></span>'
    right = f'<a href="{relative(after["url"],depth)}"><small>下一节</small>{escaped(after["title"])}</a>' if after else '<span></span>'
    return f'<nav class="next-prev" aria-label="相邻章节">{left}{right}</nav>'

def footer(depth):
    return f'<footer class="footer"><a href="{GITHUB}">GitHub 仓库</a><a href="{relative("downloads/C艹学习笔记v5.0-页码版.pdf",depth)}" download>下载 PDF</a><span>从手算、推导和反例中理解算法。</span></footer>'

def search_entries(page, section):
    entries = []
    soup = page['soup']
    for heading in soup.find_all(re.compile('^h[1-6]$')):
        collected = []
        for sibling in heading.next_siblings:
            if getattr(sibling,'name',None) and re.match('^h[1-6]$',sibling.name):
                break
            text = sibling.get_text(' ',strip=True) if hasattr(sibling,'get_text') else str(sibling).strip()
            if text:
                collected.append(text)
        entries.append({'title':heading.get_text(),'section':section,'url':page['url']+'#'+heading['id'],
                        'text':re.sub(r'\s+',' ',' '.join(collected))})
    return entries

def write_page(page, content, depth=1, reader=True):
    target = OUT/page['url']
    target.parent.mkdir(parents=True,exist_ok=True)
    target.write_text(shell(page,content,depth,reader),encoding='utf-8')

def ensure_vendors():
    vendor = OUT/'static/vendor'
    vendor.mkdir(parents=True,exist_ok=True)
    resources = {
        'tex-svg.js':'https://cdn.jsdelivr.net/npm/mathjax@3.2.2/es5/tex-svg.js',
        'mathjax-LICENSE.txt':'https://cdn.jsdelivr.net/npm/mathjax@3.2.2/LICENSE',
        'mermaid.min.js':'https://cdn.jsdelivr.net/npm/mermaid@10.9.3/dist/mermaid.min.js',
        'mermaid-LICENSE.txt':'https://cdn.jsdelivr.net/npm/mermaid@10.9.3/LICENSE',
    }
    for name,url in resources.items():
        target = vendor/name
        if not target.exists():
            with urllib.request.urlopen(url,timeout=60) as response:
                target.write_bytes(response.read())
    (vendor/'README.md').write_text('浏览器公式与图解运行库，随站点本地托管。\n\n'+
        '\n'.join(f'- [{name}]({url})' for name,url in resources.items())+'\n',encoding='utf-8')

source_text = SOURCE.read_text(encoding='utf-8')
groups,pages = split_note(source_text)
assert ''.join(page['markdown'] for page in pages) == source_text[source_text.index('## 序言'):]
manifest = json.loads((ROOT/'manifest.json').read_text(encoding='utf-8'))
source_to_page = {(ROOT/item['explanation']).resolve():'answers/'+item['id']+'.html' for item in manifest}
for readme in (ROOT/'solutions').glob('*/README.md'):
    source_to_page[readme.resolve()] = 'answers/index.html#'+readme.parent.name

OUT.mkdir(exist_ok=True)
(OUT/'.nojekyll').write_text('',encoding='utf-8')
for filename in ['site.css','site.js']:
    (OUT/'static').mkdir(exist_ok=True)
    shutil.copy2(ROOT/'tools/site'/filename,OUT/'static'/filename)
(OUT/'static/favicon.svg').write_text('<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 64 64"><rect width="64" height="64" rx="12" fill="#215ca2"/><path d="M27 19h-7L10 32l10 13h7M37 19h7l10 13-10 13h-7" fill="none" stroke="white" stroke-width="4"/></svg>',encoding='utf-8')
for source,target in [(ROOT/'notes/C艹学习笔记.assets',OUT/'media/notes'),(ROOT/'assets',OUT/'media/solutions')]:
    shutil.copytree(source,target,dirs_exist_ok=True)
(OUT/'downloads').mkdir(exist_ok=True)
shutil.copy2(PDF,OUT/'downloads'/PDF.name)
shutil.copy2(SOURCE,OUT/'downloads'/SOURCE.name)
ensure_vendors()

headings = [0]
search_index = []
for page in pages:
    prepare_page(page,SOURCE,headings)
    search_index.extend(search_entries(page,groups[page['group']]['title']))

for page in pages:
    content = str(page['soup'])
    if page['overview']:
        children = groups[page['group']]['pages'][1:]
        content += '<nav class="chapter-list" aria-label="本部分章节">'+''.join(
            f'<a href="{Path(child["url"]).name}">{escaped(child["title"])}<span>阅读 →</span></a>' for child in children)+'</nav>'
    write_page(page,content)

group_titles = {}
for readme in (ROOT/'solutions').glob('*/README.md'):
    group_titles[readme.parent.name] = readme.read_text(encoding='utf-8').splitlines()[0].lstrip('# ')
for item in manifest:
    source = ROOT/item['explanation']
    page = {'title':item['id']+' '+item['title'],'url':'answers/'+item['id']+'.html',
            'markdown':source.read_text(encoding='utf-8'),'kind':'answer','source':item['explanation']}
    prepare_page(page,source,[0])
    search_index.extend(search_entries(page,'题解 · '+page['title']))
    write_page(page,str(page['soup']))

answer_groups = ''
for group,title in group_titles.items():
    items = [item for item in manifest if item['group']==group]
    links = ''.join(f'<li data-answer-search="{escaped((item["id"]+" "+item["title"]+" "+title).lower())}"><a href="{item["id"]}.html"><code>{escaped(item["id"])}</code><span>{escaped(item["title"])}</span><small>建模 · 手算 · 实现</small></a></li>' for item in items)
    answer_groups += f'<section class="answer-group" id="{group}"><h2>{escaped(title)} <small>· {len(items)} 题</small></h2><ul class="answer-list">{links}</ul></section>'
group_links = ''.join(f'<a href="#{group}">{escaped(title)}</a>' for group,title in group_titles.items())
answers = {'title':'练习题解','url':'answers/index.html','kind':'answers','headings':[]}
write_page(answers,'<h1>练习题解</h1><p>共 107 道在线题目与 4 项面向对象练习。先独立尝试，再按需要查看推导、手算、过程图和带注释代码。</p><label for="answer-filter">按题号、题名或章节筛选</label><input class="answer-search" id="answer-filter" type="search" placeholder="例如 P1605、迷宫、动态规划"><nav class="answer-groups" aria-label="题解分类">'+group_links+'</nav>'+answer_groups)

route_page = next(page for page in pages if page['title']=='按学习目标选择必读路线')
route_targets = []
for keyword in ['零基础起步','从 C 转到 C++','ACM 入门','C++ 系统学习']:
    heading = next(heading for heading in route_page['headings'] if heading['title'].startswith(keyword))
    route_targets.append(route_page['url']+'#'+heading['id'])
routes = ''.join(f'<a class="route" href="{url}"><small>路线 {i+1:02d}</small><h3>{title}</h3><p>{text}</p></a>' for i,(url,title,text) in enumerate(zip(route_targets,
    ['零基础起步','从 C 转到 C++','ACM 入门','C++ 系统学习'],
    ['从输入、判断和循环开始，逐步写出能运行的程序。','从引用和类型参数走向标准库，补齐工具之间的依赖。','沿着题目需要学习算法，用比赛与复盘检查理解。','把对象、资源与标准库的使用接回类型和工作原理。'])))
parts = ''.join(f'<a href="{group["pages"][0]["url"]}"><span>{escaped(group["title"])}</span><small>{len(group["pages"])-1} 节 →</small></a>' for group in groups)
home = {'title':'C++ / ACM 自学笔记','url':'index.html','kind':'home'}
content = f'''<main id="main" class="home"><section class="hero"><div><div class="eyebrow">C++17 · ACM 入门 · 自学笔记 v5.0</div><h1>从写出第一段程序，<br>到独立推导解题方法。</h1><p class="intro">从应用开始，跟着具体数据手算，让代码、图解和推导相互对应。先选一条适合自己的学习路线，再沿着问题逐步扩展知识。</p><div class="actions"><a class="button primary" href="{route_page['url']}">选择学习路线 →</a><a class="button" href="downloads/{PDF.name}" download>下载 PDF · {PDF_PAGES} 页</a></div><a id="continue-reading" class="continue-reading" hidden></a></div><div class="hero-path"><div><span>01</span>用程序表达题意<small>语法基础 · 标准库 · 对象</small></div><div><span>02</span>从条件与目标推导模型<small>手算 · 反例 · 方法比较</small></div><div><span>03</span>从搜索走向状态转移<small>回溯 · 记忆化 · 动态规划</small></div><div><span>04</span>把理解放回题目中检验<small>111 份题解 · 图解 · 注释实现</small></div></div></section><section><div class="section-intro"><h2>按起点选择学习路线</h2><p>只读当前需要的章节，再用练习检查理解。</p></div><div class="routes">{routes}</div></section><section><div class="section-intro"><h2>完整笔记</h2><p>按章节阅读，也可以搜索主题与接口。</p></div><nav class="home-parts" aria-label="笔记各部分">{parts}</nav></section><section class="solution-banner"><div><h2>练习题解，留到独立尝试之后。</h2><p>按章节和题号查看建模、手算与过程；看懂之后，合上答案再写一遍。</p></div><a class="button" href="answers/index.html">查阅 111 份题解 →</a></section>{footer(0)}</main>'''
write_page(home,content,0,False)

(OUT/'search-index.json').write_text(json.dumps(search_index,ensure_ascii=False,separators=(',',':')),encoding='utf-8')
(OUT/'robots.txt').write_text('User-agent: *\nAllow: /\nSitemap: '+SITE+'sitemap.xml\n',encoding='utf-8')
all_urls = ['index.html','answers/index.html']+[page['url'] for page in pages]+['answers/'+item['id']+'.html' for item in manifest]
(OUT/'sitemap.xml').write_text('<?xml version="1.0" encoding="UTF-8"?>\n<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">'+''.join('<url><loc>'+escaped(SITE+url)+'</loc></url>' for url in all_urls)+'</urlset>',encoding='utf-8')
not_found = {'title':'页面未找到','url':'404.html','kind':'home'}
write_page(not_found,'<main class="home" id="main"><h1>页面未找到</h1><p>从目录中继续查阅笔记，或搜索主题和题号。</p><a class="button primary" href="'+SITE+'">返回首页</a></main>',0,False)

report = {'note_sha256':hashlib.sha256(SOURCE.read_bytes()).hexdigest(),'pdf_sha256':hashlib.sha256(PDF.read_bytes()).hexdigest(),
    'pdf_pages':PDF_PAGES,'chapter_pages':len(pages),'note_headings':headings[0]+1,'answer_pages':len(manifest),'search_entries':len(search_index),
    'note_images':sum(len(page['soup'].find_all('img')) for page in pages),'site':SITE}
(OUT/'build-info.json').write_text(json.dumps(report,ensure_ascii=False,indent=2),encoding='utf-8')
print(json.dumps(report,ensure_ascii=False),flush=True)

"""检查全部静态页面的内部文件、章节锚点和下载文件。"""
from pathlib import Path
import hashlib
import json
from urllib.parse import unquote,urlparse
from bs4 import BeautifulSoup

root = Path(__file__).resolve().parents[1]
site = root/'docs'
pages = {path.resolve():BeautifulSoup(path.read_text(encoding='utf-8'),'html.parser') for path in site.rglob('*.html')}
errors = []
links = 0
images = 0
for path,soup in pages.items():
    ids = [tag['id'] for tag in soup.find_all(id=True)]
    if len(ids) != len(set(ids)):
        errors.append(f'重复锚点：{path.relative_to(site)}')
    if soup.select('pre a'):
        errors.append(f'代码行中存在链接：{path.relative_to(site)}')
    for tag,attribute in [('a','href'),('img','src'),('script','src'),('link','href')]:
        for element in soup.find_all(tag):
            value = element.get(attribute)
            if not value:
                continue
            parsed = urlparse(value)
            if parsed.scheme or parsed.netloc:
                continue
            target = (path.parent/unquote(parsed.path)).resolve() if parsed.path else path
            if not target.is_relative_to(site.resolve()):
                errors.append(f'站点外部相对路径：{path.name} → {value}')
                continue
            if not target.is_file():
                errors.append(f'文件不存在：{path.name} → {value}')
                continue
            if parsed.fragment and target in pages and unquote(parsed.fragment) not in {x['id'] for x in pages[target].find_all(id=True)}:
                errors.append(f'锚点不存在：{path.name} → {value}')
            links += tag=='a'
            images += tag=='img'
for entry in json.loads((site/'search-index.json').read_text(encoding='utf-8')):
    parsed = urlparse(entry['url'])
    target = (site/parsed.path).resolve()
    if target not in pages or parsed.fragment not in {x['id'] for x in pages[target].find_all(id=True)}:
        errors.append('搜索目标不存在：'+entry['url'])
for name in ['C艹学习笔记v5.0.md','C艹学习笔记v5.0-页码版.pdf']:
    assert (root/'notes'/name).read_bytes()==(site/'downloads'/name).read_bytes(),f'下载文件与笔记版本不一致：{name}'
if errors:
    raise SystemExit('\n'.join(errors))
report = {'html_pages':len(pages),'internal_links':links,'image_references':images,'errors':errors,
    'pdf_sha256':hashlib.sha256((site/'downloads/C艹学习笔记v5.0-页码版.pdf').read_bytes()).hexdigest()}
print(json.dumps(report,ensure_ascii=False),flush=True)

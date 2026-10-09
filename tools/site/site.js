(() => {
  const root = document.body.dataset.siteRoot || './';
  const storage = {
    get(key) { try { return localStorage.getItem(key); } catch { return null; } },
    set(key, value) { try { localStorage.setItem(key, value); } catch {} }
  };
  const themeButton = document.querySelector('[data-theme-toggle]');
  themeButton?.addEventListener('click', () => {
    const next = document.documentElement.dataset.theme === 'dark' ? 'light' : 'dark';
    document.documentElement.dataset.theme = next;
    storage.set('cpp-notes-theme', next);
    themeButton.textContent = next === 'dark' ? '浅色' : '深色';
  });
  if (themeButton) themeButton.textContent = document.documentElement.dataset.theme === 'dark' ? '浅色' : '深色';

  const sidebar = document.querySelector('.sidebar');
  const backdrop = document.querySelector('.mobile-backdrop');
  const menu = document.querySelector('.menu-toggle');
  const closeMenu = () => {
    sidebar?.classList.remove('open');
    backdrop?.classList.remove('visible');
    menu?.setAttribute('aria-expanded', 'false');
  };
  menu?.addEventListener('click', () => {
    const opened = sidebar?.classList.toggle('open');
    backdrop?.classList.toggle('visible', !!opened);
    menu.setAttribute('aria-expanded', String(!!opened));
  });
  backdrop?.addEventListener('click', closeMenu);
  const currentChapter = sidebar?.querySelector('a.current');
  if (currentChapter) {
    const offset = currentChapter.getBoundingClientRect().top-sidebar.getBoundingClientRect().top;
    // 只滚动目录自身，避免窄屏时把正文一起横向移动。
    if (offset>sidebar.clientHeight-80 || offset<0) sidebar.scrollTop += offset-sidebar.clientHeight/2;
  }

  for (const pre of document.querySelectorAll('article pre:not(.mermaid)')) {
    const wrapper = document.createElement('div');
    wrapper.className = 'codebox';
    pre.before(wrapper);
    wrapper.append(pre);
    const button = document.createElement('button');
    button.type = 'button';
    button.className = 'copy-code';
    button.textContent = '复制';
    button.setAttribute('aria-label', '复制代码或样例文本');
    button.addEventListener('click', async () => {
      const text = (pre.querySelector('code') || pre).textContent;
      try {
        await navigator.clipboard.writeText(text);
        button.textContent = '已复制';
      } catch {
        button.textContent = '请选中复制';
      }
      setTimeout(() => { button.textContent = '复制'; }, 1800);
    });
    wrapper.append(button);
  }
  for (const table of document.querySelectorAll('article table')) {
    const wrapper = document.createElement('div');
    wrapper.className = 'table-scroll';
    wrapper.tabIndex = 0;
    wrapper.setAttribute('role', 'region');
    wrapper.setAttribute('aria-label', '可左右滚动的表格');
    table.before(wrapper);
    wrapper.append(table);
  }

  const imageDialog = document.querySelector('#image-dialog');
  if (imageDialog) {
    const enlarged = imageDialog.querySelector('img');
    const openImage = image => {
      enlarged.src = image.src;
      enlarged.alt = image.alt;
      imageDialog.showModal();
    };
    for (const image of document.querySelectorAll('article img')) {
      image.tabIndex = 0;
      image.setAttribute('role', 'button');
      image.setAttribute('aria-label', `放大图解：${image.alt || '过程图'}`);
      image.addEventListener('click', () => openImage(image));
      image.addEventListener('keydown', event => {
        if (event.key === 'Enter' || event.key === ' ') {
          event.preventDefault();
          openImage(image);
        }
      });
    }
    imageDialog.querySelector('button').addEventListener('click', () => imageDialog.close());
    imageDialog.addEventListener('click', event => { if (event.target === imageDialog) imageDialog.close(); });
  }

  const dialog = document.querySelector('#search-dialog');
  const input = dialog?.querySelector('input');
  const results = dialog?.querySelector('.search-results');
  let searchData;
  let loading;
  let searchSequence = 0;
  const loadSearch = () => loading ||= fetch(root + 'search-index.json').then(response => {
    if (!response.ok) throw new Error('搜索索引读取失败');
    return response.json();
  }).then(data => { searchData = data; return data; });
  const message = text => {
    results.replaceChildren();
    const element = document.createElement('div');
    element.className = 'search-empty';
    element.textContent = text;
    results.append(element);
  };
  const search = async () => {
    const sequence = ++searchSequence;
    const query = input.value.trim().toLowerCase();
    if (!query) { message('输入主题、函数名或题号，例如：记忆化、vector、P1605。'); return; }
    try {
      message('正在查找…');
      const data = searchData || await loadSearch();
      if (sequence !== searchSequence) return;
      const words = query.split(/\s+/);
      const hits = data.map(entry => {
        const title = entry.title.toLowerCase();
        const text = (entry.title + ' ' + entry.section + ' ' + entry.text).toLowerCase();
        if (!words.every(word => text.includes(word))) return null;
        const score = words.reduce((total, word) => total + (title.includes(word) ? 10 : 1), 0);
        return {entry, score};
      }).filter(Boolean).sort((a,b) => b.score-a.score).slice(0,25);
      results.replaceChildren();
      if (!hits.length) { message('没有找到对应内容，可试试更短的关键词或题号。'); return; }
      for (const {entry} of hits) {
        const link = document.createElement('a');
        link.href = root + entry.url;
        const section = document.createElement('small');
        section.textContent = entry.section;
        const title = document.createElement('strong');
        title.textContent = entry.title;
        const preview = document.createElement('p');
        const lower = entry.text.toLowerCase();
        const position = lower.indexOf(words[0]);
        const start = Math.max(0,position-30);
        preview.textContent = (start ? '…' : '') + entry.text.slice(start,start+135);
        link.append(section,title,preview);
        link.addEventListener('click', () => dialog.close());
        results.append(link);
      }
    } catch { message('搜索索引暂时无法读取，请使用左侧目录查阅。'); }
  };
  const openSearch = () => {
    closeMenu();
    dialog.showModal();
    input.focus();
    search();
  };
  for (const button of document.querySelectorAll('[data-search-open]')) button.addEventListener('click', openSearch);
  dialog?.querySelector('button')?.addEventListener('click', () => dialog.close());
  dialog?.addEventListener('click', event => { if (event.target === dialog) dialog.close(); });
  input?.addEventListener('input', search);
  document.addEventListener('keydown', event => {
    if ((event.ctrlKey || event.metaKey) && event.key.toLowerCase() === 'k') {
      event.preventDefault();
      openSearch();
    }
    if (event.key === 'Escape') closeMenu();
  });

  const answerFilter = document.querySelector('#answer-filter');
  answerFilter?.addEventListener('input', () => {
    const query = answerFilter.value.trim().toLowerCase();
    for (const item of document.querySelectorAll('[data-answer-search]')) item.hidden = !item.dataset.answerSearch.includes(query);
    for (const group of document.querySelectorAll('.answer-group')) group.hidden = ![...group.querySelectorAll('li')].some(item => !item.hidden);
  });

  const headings = [...document.querySelectorAll('article h2[id],article h3[id],article h4[id],article h5[id],article h6[id]')];
  const toc = new Map([...document.querySelectorAll('.page-toc a')].map(link => [link.hash.slice(1),link]));
  let activeHeading = '';
  const updatePosition = () => {
    const visible = headings.filter(heading => heading.getBoundingClientRect().top < 150);
    const active = visible[visible.length-1] || headings[0];
    if (!active || active.id === activeHeading) return;
    activeHeading = active.id;
    for (const [id,link] of toc) link.classList.toggle('active',id===activeHeading);
    if (document.body.dataset.pageKind === 'chapter') storage.set('cpp-notes-last',JSON.stringify({
      url:document.body.dataset.pageUrl + '#' + activeHeading,
      title:document.body.dataset.pageTitle
    }));
  };
  let scheduled = false;
  addEventListener('scroll', () => {
    if (!scheduled) requestAnimationFrame(() => { updatePosition(); scheduled=false; });
    scheduled=true;
  }, {passive:true});
  const resume = document.querySelector('#continue-reading');
  if (resume) {
    try {
      const last = JSON.parse(storage.get('cpp-notes-last'));
      if (last?.url?.startsWith('chapters/') && !last.url.includes('..')) {
        resume.href = root+last.url;
        resume.textContent = '继续阅读：'+last.title;
        resume.hidden=false;
      }
    } catch {}
  }

  window.siteReady = (async () => {
    if (window.MathJax?.startup?.promise) await MathJax.startup.promise;
    if (document.querySelector('.math')) await MathJax.typesetPromise();
    if (document.querySelector('.mermaid')) {
      mermaid.initialize({startOnLoad:false,securityLevel:'strict',theme:'base',themeVariables:{
        fontFamily:'Microsoft YaHei, sans-serif',primaryColor:'#edf3f9',primaryBorderColor:'#2563eb',primaryTextColor:'#17324d',lineColor:'#2563eb',secondaryColor:'#dcfce7',tertiaryColor:'#fff7ed'
      }});
      await mermaid.run({querySelector:'.mermaid'});
    }
    // 公式排版和图解展开后，再定位页面内的章节锚点。
    if (location.hash) document.getElementById(decodeURIComponent(location.hash.slice(1)))?.scrollIntoView();
    updatePosition();
  })().catch(error => { console.error('章节排版失败',error); throw error; });
})();

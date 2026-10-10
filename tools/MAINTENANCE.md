# 网页维护说明

修改笔记、题解或网页样式后，用下面的命令重新生成并检查网页。命令均在仓库根目录执行。

## 仓库目录

| 目录 | 用途 |
| --- | --- |
| `notes/` | 完整笔记、PDF和正文插图 |
| `solutions/`、`code/` | 题解 Markdown 和对应的独立 C++ 源文件 |
| `assets/` | 题解中的过程图 |
| `tests/`、`manifest.json` | 题目索引、样例与本地核对程序 |
| `tools/` | 网页构建脚本与页面样式 |
| `docs/` | 生成的静态网页，由 GitHub Pages 发布 |

## 构建与预览

构建脚本使用 Python 和 Pandoc。先安装 Pandoc，并将它加入 PATH，再执行：

```shell
# 安装网页构建依赖。
python -m pip install -r tools/requirements-site.txt
# 按现有正文重新生成章节、题解页和搜索索引。
python tools/build_site.py
# 检查站点内部链接、章节锚点、插图与下载文件。
python tools/check_site.py
# 启动本地预览，浏览器打开 http://localhost:8000。
python -m http.server 8000 --directory docs
```

## 发布

GitHub Pages 从 `main` 分支的 `/docs` 目录发布网页。更新内容并检查通过后，把重新生成的 `docs/` 一起提交到 `main` 分支。

公式与 Mermaid 图解的运行库随站点保存。版本、来源及许可证见 [运行库说明](../docs/static/vendor/README.md)。

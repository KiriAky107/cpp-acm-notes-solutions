# C++／ACM 自学笔记配套题解

对应笔记 v5.0 的练习。这里收录正文逐项列出的 107 道在线题目，以及面向对象的 4 项自拟练习，共 111 份参考解答。同一题在不同章节出现时共用一份题解，题解开头列出对应章节。

## （一） 阅读方法

先打开原题独立尝试，卡住时按“任务与输出目标 → 建模与推导 → 手算与过程 → 带注释实现”逐段查看。看到一个足够继续思考的提示后，返回自己的程序。做完后合上答案，重新解释状态、动作和复杂度。

每份程序可以单独编译，全部采用序言中的 GNU C++17 竞赛模板：`#define int long long`、`#define endl '\n'`、`solve()` 与 `signed main()`。题目的单组读入和计算写在 `solve()` 中，主函数设置快速 I/O 并按测试组数调用；程序中保留中文注释，图解与代码的状态含义一致。

## （二） 按章节查阅

| 题解章节 | 题目数 |
| --- | --- |
| [语言基础与条件建模](solutions/01-language/README.md) | 16 |
| [STL 容器与操作模拟](solutions/02-stl/README.md) | 20 |
| [方法选择与事件模拟](solutions/03-modeling/README.md) | 4 |
| [大整数四则运算](solutions/04-bigint/README.md) | 5 |
| [枚举、前缀和、差分与排序](solutions/05-basics/README.md) | 6 |
| [基础数论与快速幂](solutions/06-number/README.md) | 6 |
| [双指针、窗口与二分](solutions/07-pointers/README.md) | 7 |
| [贪心策略](solutions/08-greedy/README.md) | 5 |
| [递归、回溯、DFS、BFS 与记忆化](solutions/09-search/README.md) | 12 |
| [动态规划](solutions/10-dp/README.md) | 14 |
| [树、并查集与图论](solutions/11-graph/README.md) | 12 |
| [面向对象的四项练习](solutions/12-objects/README.md) | 4 |

## （三） 按题号查阅

在本页用 Ctrl+F 查找题号；点击题名打开推导，原题列返回评测平台。序言中的 HDU 题库入口和后记的比赛题库用于自行选题，本索引对应正文明确列出的练习题。

| 题号 | 题解 | 所属章节 | 原题 |
| --- | --- | --- | --- |
| P1001 | [A+B Problem](solutions/01-language/P1001.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P1001) |
| P5703 | [苹果采购](solutions/01-language/P5703.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P5703) |
| P5710 | [数的性质](solutions/01-language/P5710.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P5710) |
| P1100 | [高低位交换](solutions/01-language/P1100.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P1100) |
| P5712 | [Apples](solutions/01-language/P5712.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P5712) |
| P5721 | [数字直角三角形](solutions/01-language/P5721.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P5721) |
| P5723 | [质数口袋](solutions/01-language/P5723.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P5723) |
| P1428 | [小鱼比可爱](solutions/01-language/P1428.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P1428) |
| P5732 | [杨辉三角](solutions/01-language/P5732.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P5732) |
| P1554 | [梦中的统计](solutions/01-language/P1554.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P1554) |
| CF4-A | [Watermelon](solutions/01-language/CF4-A.md) | 语言基础与条件建模 | [原题](https://codeforces.com/problemset/problem/4/A) |
| P5711 | [闰年判断](solutions/01-language/P5711.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P5711) |
| P5709 | [苹果和虫子](solutions/01-language/P5709.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P5709) |
| P1046 | [陶陶摘苹果](solutions/01-language/P1046.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P1046) |
| P5717 | [三角形分类](solutions/01-language/P5717.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P5717) |
| P1085 | [不高兴的津津](solutions/01-language/P1085.md) | 语言基础与条件建模 | [原题](https://www.luogu.com.cn/problem/P1085) |
| P5733 | [自动修正](solutions/02-stl/P5733.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P5733) |
| P1427 | [小鱼的数字游戏](solutions/02-stl/P1427.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1427) |
| P1308 | [统计单词数](solutions/02-stl/P1308.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1308) |
| P1093 | [奖学金](solutions/02-stl/P1093.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1093) |
| P1177 | [排序](solutions/02-stl/P1177.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1177) |
| P1059 | [明明的随机数](solutions/02-stl/P1059.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1059) |
| P1160 | [队列安排](solutions/02-stl/P1160.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1160) |
| P1449 | [后缀表达式](solutions/02-stl/P1449.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1449) |
| P1241 | [括号序列](solutions/02-stl/P1241.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1241) |
| P1996 | [约瑟夫问题](solutions/02-stl/P1996.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1996) |
| P1540 | [机器翻译](solutions/02-stl/P1540.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1540) |
| CF4-C | [Registration System](solutions/02-stl/CF4-C.md) | STL 容器与操作模拟 | [原题](https://codeforces.com/problemset/problem/4/C) |
| P5266 | [学籍管理](solutions/02-stl/P5266.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P5266) |
| P2234 | [营业额统计](solutions/02-stl/P2234.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P2234) |
| P3370 | [字符串哈希](solutions/02-stl/P3370.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P3370) |
| P3378 | [堆](solutions/02-stl/P3378.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P3378) |
| P1631 | [序列合并](solutions/02-stl/P1631.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1631) |
| P1886 | [滑动窗口](solutions/02-stl/P1886.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1886) |
| P1440 | [求 m 区间内的最小值](solutions/02-stl/P1440.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P1440) |
| P2073 | [送花](solutions/02-stl/P2073.md) | STL 容器与操作模拟 | [原题](https://www.luogu.com.cn/problem/P2073) |
| P1102 | [A-B 数对](solutions/03-modeling/P1102.md) | 方法选择与事件模拟 | [原题](https://www.luogu.com.cn/problem/P1102) |
| CF702-B | [Powers of Two](solutions/03-modeling/CF702-B.md) | 方法选择与事件模拟 | [原题](https://codeforces.com/problemset/problem/702/B) |
| P2058 | [海港](solutions/03-modeling/P2058.md) | 方法选择与事件模拟 | [原题](https://www.luogu.com.cn/problem/P2058) |
| P1065 | [作业调度方案](solutions/03-modeling/P1065.md) | 方法选择与事件模拟 | [原题](https://www.luogu.com.cn/problem/P1065) |
| P1601 | [高精度加法](solutions/04-bigint/P1601.md) | 大整数四则运算 | [原题](https://www.luogu.com.cn/problem/P1601) |
| P2142 | [高精度减法](solutions/04-bigint/P2142.md) | 大整数四则运算 | [原题](https://www.luogu.com.cn/problem/P2142) |
| P1303 | [A*B Problem](solutions/04-bigint/P1303.md) | 大整数四则运算 | [原题](https://www.luogu.com.cn/problem/P1303) |
| P1480 | [A/B Problem](solutions/04-bigint/P1480.md) | 大整数四则运算 | [原题](https://www.luogu.com.cn/problem/P1480) |
| P1932 | [大整数五种运算](solutions/04-bigint/P1932.md) | 大整数四则运算 | [原题](https://www.luogu.com.cn/problem/P1932) |
| P2089 | [烤鸡](solutions/05-basics/P2089.md) | 枚举、前缀和、差分与排序 | [原题](https://www.luogu.com.cn/problem/P2089) |
| P8218 | [求区间和](solutions/05-basics/P8218.md) | 枚举、前缀和、差分与排序 | [原题](https://www.luogu.com.cn/problem/P8218) |
| P2367 | [语文成绩](solutions/05-basics/P2367.md) | 枚举、前缀和、差分与排序 | [原题](https://www.luogu.com.cn/problem/P2367) |
| P3397 | [地毯](solutions/05-basics/P3397.md) | 枚举、前缀和、差分与排序 | [原题](https://www.luogu.com.cn/problem/P3397) |
| P1908 | [逆序对](solutions/05-basics/P1908.md) | 枚举、前缀和、差分与排序 | [原题](https://www.luogu.com.cn/problem/P1908) |
| P1496 | [火烧赤壁](solutions/05-basics/P1496.md) | 枚举、前缀和、差分与排序 | [原题](https://www.luogu.com.cn/problem/P1496) |
| P1029 | [最大公约数和最小公倍数问题](solutions/06-number/P1029.md) | 基础数论与快速幂 | [原题](https://www.luogu.com.cn/problem/P1029) |
| P3383 | [线性筛素数](solutions/06-number/P3383.md) | 基础数论与快速幂 | [原题](https://www.luogu.com.cn/problem/P3383) |
| P1075 | [质因数分解](solutions/06-number/P1075.md) | 基础数论与快速幂 | [原题](https://www.luogu.com.cn/problem/P1075) |
| P1226 | [快速幂](solutions/06-number/P1226.md) | 基础数论与快速幂 | [原题](https://www.luogu.com.cn/problem/P1226) |
| CF742-A | [Arpa’s hard exam and Mehrdad’s naive cheat](solutions/06-number/CF742-A.md) | 基础数论与快速幂 | [原题](https://codeforces.com/problemset/problem/742/A) |
| P1217 | [回文质数](solutions/06-number/P1217.md) | 基础数论与快速幂 | [原题](https://www.luogu.com.cn/problem/P1217) |
| CF279-B | [Books](solutions/07-pointers/CF279-B.md) | 双指针、窗口与二分 | [原题](https://codeforces.com/problemset/problem/279/B) |
| P1638 | [逛画展](solutions/07-pointers/P1638.md) | 双指针、窗口与二分 | [原题](https://www.luogu.com.cn/problem/P1638) |
| P1182 | [数列分段 Section II](solutions/07-pointers/P1182.md) | 双指针、窗口与二分 | [原题](https://www.luogu.com.cn/problem/P1182) |
| P1873 | [砍树](solutions/07-pointers/P1873.md) | 双指针、窗口与二分 | [原题](https://www.luogu.com.cn/problem/P1873) |
| P2678 | [跳石头](solutions/07-pointers/P2678.md) | 双指针、窗口与二分 | [原题](https://www.luogu.com.cn/problem/P2678) |
| P3382 | [三分](solutions/07-pointers/P3382.md) | 双指针、窗口与二分 | [原题](https://www.luogu.com.cn/problem/P3382) |
| P2249 | [查找](solutions/07-pointers/P2249.md) | 双指针、窗口与二分 | [原题](https://www.luogu.com.cn/problem/P2249) |
| CF996-A | [Hit the Lottery](solutions/08-greedy/CF996-A.md) | 贪心策略 | [原题](https://codeforces.com/problemset/problem/996/A) |
| P1803 | [线段覆盖](solutions/08-greedy/P1803.md) | 贪心策略 | [原题](https://www.luogu.com.cn/problem/P1803) |
| P1090 | [合并果子](solutions/08-greedy/P1090.md) | 贪心策略 | [原题](https://www.luogu.com.cn/problem/P1090) |
| P2240 | [部分背包问题](solutions/08-greedy/P2240.md) | 贪心策略 | [原题](https://www.luogu.com.cn/problem/P2240) |
| P1016 | [旅行家的预算](solutions/08-greedy/P1016.md) | 贪心策略 | [原题](https://www.luogu.com.cn/problem/P1016) |
| P1036 | [选数](solutions/09-search/P1036.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P1036) |
| P1219 | [八皇后](solutions/09-search/P1219.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P1219) |
| P1605 | [迷宫](solutions/09-search/P1605.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P1605) |
| P5318 | [查找文献](solutions/09-search/P5318.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P5318) |
| P1451 | [求细胞数量](solutions/09-search/P1451.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P1451) |
| P1596 | [湖计数](solutions/09-search/P1596.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P1596) |
| P1162 | [填涂颜色](solutions/09-search/P1162.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P1162) |
| P1141 | [01 迷宫](solutions/09-search/P1141.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P1141) |
| P1443 | [马的遍历](solutions/09-search/P1443.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P1443) |
| P1135 | [奇怪的电梯](solutions/09-search/P1135.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P1135) |
| P1434 | [滑雪](solutions/09-search/P1434.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P1434) |
| P1242 | [新汉诺塔](solutions/09-search/P1242.md) | 递归、回溯、DFS、BFS 与记忆化 | [原题](https://www.luogu.com.cn/problem/P1242) |
| P1255 | [数楼梯](solutions/10-dp/P1255.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P1255) |
| P1115 | [最大子段和](solutions/10-dp/P1115.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P1115) |
| P1387 | [最大正方形](solutions/10-dp/P1387.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P1387) |
| P1020 | [导弹拦截](solutions/10-dp/P1020.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P1020) |
| P1439 | [两个排列的最长公共子序列](solutions/10-dp/P1439.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P1439) |
| P1435 | [回文字串](solutions/10-dp/P1435.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P1435) |
| P2758 | [编辑距离](solutions/10-dp/P2758.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P2758) |
| P1048 | [采药](solutions/10-dp/P1048.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P1048) |
| P1049 | [装箱问题](solutions/10-dp/P1049.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P1049) |
| P1616 | [疯狂的采药](solutions/10-dp/P1616.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P1616) |
| P1164 | [小 A 点菜](solutions/10-dp/P1164.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P1164) |
| P2842 | [纸币问题 1](solutions/10-dp/P2842.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P2842) |
| P1002 | [过河卒](solutions/10-dp/P1002.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P1002) |
| P2679 | [子串](solutions/10-dp/P2679.md) | 动态规划 | [原题](https://www.luogu.com.cn/problem/P2679) |
| P4913 | [二叉树深度](solutions/11-graph/P4913.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/P4913) |
| P3884 | [二叉树问题](solutions/11-graph/P3884.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/P3884) |
| P3367 | [并查集](solutions/11-graph/P3367.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/P3367) |
| P1551 | [亲戚](solutions/11-graph/P1551.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/P1551) |
| B3643 | [图的存储](solutions/11-graph/B3643.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/B3643) |
| P1330 | [封锁阳光大学](solutions/11-graph/P1330.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/P1330) |
| P3371 | [单源最短路径（弱化版）](solutions/11-graph/P3371.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/P3371) |
| P4779 | [单源最短路径（标准版）](solutions/11-graph/P4779.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/P4779) |
| B3647 | [Floyd](solutions/11-graph/B3647.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/B3647) |
| B3644 | [拓扑排序／家谱树](solutions/11-graph/B3644.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/B3644) |
| P1807 | [最长路](solutions/11-graph/P1807.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/P1807) |
| P3366 | [最小生成树](solutions/11-graph/P3366.md) | 树、并查集与图论 | [原题](https://www.luogu.com.cn/problem/P3366) |
| OOP1 | [学生信息排序](solutions/12-objects/OOP1.md) | 面向对象的四项练习 | 自拟练习 |
| OOP2 | [成绩类的修改检查](solutions/12-objects/OOP2.md) | 面向对象的四项练习 | 自拟练习 |
| OOP3 | [通过 Shape 调用 Triangle 面积](solutions/12-objects/OOP3.md) | 面向对象的四项练习 | 自拟练习 |
| OOP4 | [二叉树节点的所有权](solutions/12-objects/OOP4.md) | 面向对象的四项练习 | 自拟练习 |

## （四） 编译与本地核对

例如编译某一道题：

```shell
# 编译独立源文件，再让程序从标准输入读取本地数据。
g++ -std=gnu++17 -O2 code/P1182.cpp -o solution
./solution < input.txt
```

运行仓库中的 `python tests/verify.py` 会编译全部参考实现、核对题面样例与手算例子。汉诺塔和拓扑排序存在多种合法输出，验证程序分别检查移动是否合法且步数最少，以及所有前驱是否先于后继输出。

## （五） 从答案回到独立解题

记录自己停在哪一步：读漏题意、没找到模型、无法证明、状态不够、实现或输出错误。对应地只复习那一小段推导，再做一题相似练习。参考实现展示一条完整解题路线，同一题也可以继续比较其他模型。

# CF4-A Watermelon

[原题入口](https://codeforces.com/problemset/problem/4/A)

对应章节：三、解题方法论：从题意到代码 → （四） 必要条件、充分条件与等价条件；三、解题方法论：从题意到代码 → （十） 从样例猜想到证明与构造。

## （一） 任务与输出目标

判断一个重量能否分成两份正偶数。

## （二） 建模与推导

两份正偶数相加仍是偶数，而且各自至少为 2，因此总重量至少为 4。反过来，任意不小于 4 的偶数 w 都能写成 2 与 w-2，两份都是正偶数。由两个方向的推导得到等价判断：`w>2 && w%2==0`。

## （三） 手算与过程

w=8 可分为 2 与 6；w=2 虽然是偶数，却无法分成两份正偶数。

## （四） 带注释实现

[完整源文件](../../code/CF4-A.cpp)

```cpp
#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int w;
    cin >> w;
    cout << (w > 2 && w % 2 == 0 ? "YES" : "NO") << '\n'; // 两项共同表达可分性。
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}
```

头文件 `<bits/stdc++.h>` 汇总 GNU C++ 的常用标准库，包含本程序使用的流、容器与算法；这是序言竞赛模板中的包含方式。

## （五） 复杂度

时间 $O(1)$，额外空间 $O(1)$。

[返回本章题解索引](README.md) · [返回全部题号索引](../../README.md)

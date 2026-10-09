# CF4-C Registration System

[原题入口](https://codeforces.com/problemset/problem/4/C)

对应章节：一、C++ 语法基础 → （十五） STL：容器、迭代器与算法；五、数据结构与算法 → （七） 哈希（散列）表。

## （一） 任务与输出目标

给重复注册的名字追加最小未使用的正整数后缀。

## （二） 建模与推导

输入名字只有小写字母，新生成的名字包含数字，因此不同基础名不会与生成名相撞。为每个基础名保存此前出现次数：首次输出 OK；再次出现时输出基础名与该次数，然后加一。后缀 1、2、3 按序产生，不需要反复从 1 搜索。

## （三） 手算与过程

ab、ab、cd、ab → OK、ab1、OK、ab2。

## （四） 带注释实现

[完整源文件](../../code/CF4-C.cpp)

```cpp
#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n; cin >> n;
    map<string, int> count;
    while (n--) {
        string name; cin >> name;
        int& seen = count[name]; // 首次访问会建立值为 0 的记录。
        if (seen == 0) cout << "OK\n";
        else cout << name << seen << '\n';
        ++seen; // 下次重复使用下一个后缀。
    }
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

名字最长 L，时间 $O(nL\log n)$，保存名字总空间 $O(nL)$。

[返回本章题解索引](README.md) · [返回全部题号索引](../../README.md)

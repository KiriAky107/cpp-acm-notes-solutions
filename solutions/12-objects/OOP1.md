# OOP1 学生信息排序

自拟练习：对应笔记面向对象部分。

对应章节：二、面向对象编程 → （九）面向对象部分的练习。

## （一） 任务与输出目标

用 struct 保存学生信息，按成绩降序、编号升序排序。

## （二） 建模与推导

一条记录把编号与成绩绑在一起，排序时整体移动，不会打乱对应关系。比较函数先处理成绩；同分再比较编号。使用严格比较，相同记录与自己比较得到 false。

## （三） 手算与过程

记录 (3,90)、(1,90)、(2,95) 排成 (2,95)、(1,90)、(3,90)。

## （四） 带注释实现

[完整源文件](../../code/OOP1.cpp)

```cpp
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct Student {
    int id, score;
};

void solve() {
    int n;
    cin >> n;
    vector<Student> a(n);
    for (auto& s : a)
        cin >> s.id >> s.score;
    sort(a.begin(), a.end(), [](const Student& x, const Student& y) {
        if (x.score != y.score)
            return x.score > y.score;
        return x.id < y.id; // 按两层优先级比较。
    });
    for (auto s : a)
        cout << s.id << ' ' << s.score << '\n';
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

## （五） 复杂度

时间 $O(n\log n)$，空间 $O(n)$。

[返回本章题解索引](README.md) · [返回全部题号索引](../../README.md)

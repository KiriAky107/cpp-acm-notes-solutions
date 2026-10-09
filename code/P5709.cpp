#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int m, t, s;
    cin >> m >> t >> s;
    if (t == 0) cout << 0 << '\n'; // 每个苹果瞬间吃完，已经没有完整苹果。
    else {
        int started = (s + t - 1) / t; // 包含正在吃的那一个。
        int left = m - started;
        cout << (left > 0 ? left : 0) << '\n';
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

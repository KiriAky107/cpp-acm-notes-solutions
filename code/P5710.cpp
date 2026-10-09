#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int x;
    cin >> x;
    bool p = (x % 2 == 0);       // 第一项性质：偶数。
    bool q = (4 < x && x <= 12); // 第二项性质：大于 4 且不超过 12。
    cout << (p && q) << ' ' << (p || q) << ' ' << (p != q) << ' ' << (!p && !q) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

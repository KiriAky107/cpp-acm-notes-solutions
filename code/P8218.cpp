#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) { long long x; cin >> x; sum[i] = sum[i - 1] + x; }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << sum[r] - sum[l - 1] << '\n'; // 去掉左端点之前的前缀。
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

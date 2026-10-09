#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    long double l, r;
    cin >> n >> l >> r;
    vector<long double> a(n + 1);
    for (auto& x : a)
        cin >> x;
    auto value = [&](long double x) {
        long double y = 0;
        for (long double coefficient : a)
            y = y * x + coefficient; // Horner 逐项求值。
        return y;
    };
    for (int step = 0; step < 200; ++step) {
        long double u = l + (r - l) / 3, v = r - (r - l) / 3;
        if (value(u) < value(v))
            l = u;
        else
            r = v; // 保留含峰顶的部分。
    }
    cout << fixed << setprecision(8) << (l + r) / 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    long long x, y; cin >> x >> y;
    if (y % x != 0) { cout << 0 << '\n'; return; }
    long long product = y / x, answer = 0;
    for (long long a = 1; a * a <= product; ++a) {
        if (product % a != 0) continue;
        long long b = product / a;
        if (gcd(a, b) == 1) answer += (a == b ? 1 : 2); // 还原成 P、Q 时保留两种顺序。
    }
    cout << answer << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int m, n, count[10] = {};
    cin >> m >> n;
    for (int value = m; value <= n; ++value) {
        int x = value; // 在副本上逐位拆数。
        do {
            ++count[x % 10];
            x /= 10;
        } while (x > 0);
    }
    for (int digit = 0; digit < 10; ++digit)
        cout << count[digit] << (digit == 9 ? '\n' : ' ');
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

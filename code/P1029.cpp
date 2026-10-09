#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    if (y % x != 0) {
        cout << 0 << '\n';
        return;
    }
    int product = y / x, answer = 0;
    for (int a = 1; a * a <= product; ++a) {
        if (product % a != 0)
            continue;
        int b = product / a;
        if (gcd(a, b) == 1)
            answer += (a == b ? 1 : 2); // 还原成 P、Q 时保留两种顺序。
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

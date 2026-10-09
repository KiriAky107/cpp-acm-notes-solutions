#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    int answer = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            int x;
            cin >> x;
            if (x == 1)
                f[i][j] =
                    1 + min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}); // 三块共同支撑扩张。
            answer = max(answer, f[i][j]);
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

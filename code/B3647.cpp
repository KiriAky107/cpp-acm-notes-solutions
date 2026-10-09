#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    const int inf = LLONG_MAX / 4;
    vector<vector<int>> d(n + 1, vector<int>(n + 1, inf));
    for (int i = 1; i <= n; ++i)
        d[i][i] = 0;
    while (m--) {
        int u, v;
        int w;
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = min(d[u][v], w);
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (d[i][k] != inf && d[k][j] != inf)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // 放开中间点 k。
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << d[i][j] << ' ';
        cout << '\n';
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

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0)), g(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        matrix[u][v] = matrix[v][u] = 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << matrix[i][j] << ' ';
        cout << '\n';
    }
    for (int i = 1; i <= n; ++i) {
        sort(g[i].begin(), g[i].end()); // 原输入顺序不一定等于邻居编号顺序。
        cout << g[i].size();
        for (int v : g[i])
            cout << ' ' << v;
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

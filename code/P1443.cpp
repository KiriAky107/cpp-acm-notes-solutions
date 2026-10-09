#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    --sx;
    --sy;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    dist[sx][sy] = 0;
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 8; ++d) {
            int u = x + dx[d], v = y + dy[d];
            if (u >= 0 && u < n && v >= 0 && v < m && dist[u][v] == -1) {
                dist[u][v] = dist[x][y] + 1;
                q.emplace(u, v); // 首次发现来自最短前驱层。
            }
        }
    }
    for (auto& row : dist) {
        for (int x : row)
            cout << left << setw(5) << x;
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

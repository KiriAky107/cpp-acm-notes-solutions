#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 2, vector<int>(n + 2, 0));
    vector<vector<bool>> outside(n + 2, vector<bool>(n + 2, false));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    outside[0][0] = true;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int u = x + dx[d], v = y + dy[d];
            if (u >= 0 && u <= n + 1 && v >= 0 && v <= n + 1 && !a[u][v] && !outside[u][v]) {
                outside[u][v] = true;
                q.emplace(u, v); // 从外面到达的 0 保持原样。
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == 0 && !outside[i][j])
                a[i][j] = 2;
            cout << a[i][j] << ' ';
        }
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

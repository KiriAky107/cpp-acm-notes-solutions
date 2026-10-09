#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;
    vector<vector<bool>> blocked(n + 1, vector<bool>(m + 1, false));
    int dx[9] = {0, 1, 1, -1, -1, 2, 2, -2, -2}, dy[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
    for (int d = 0; d < 9; ++d) {
        int x = hx + dx[d], y = hy + dy[d];
        if (x >= 0 && x <= n && y >= 0 && y <= m)
            blocked[x][y] = true; // 只标地图中的控制点。
    }
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    for (int x = 0; x <= n; ++x)
        for (int y = 0; y <= m; ++y) {
            if (blocked[x][y])
                continue;
            if (x == 0 && y == 0) {
                f[x][y] = 1;
                continue;
            }
            if (x > 0)
                f[x][y] += f[x - 1][y];
            if (y > 0)
                f[x][y] += f[x][y - 1]; // 两类最后一步的路径相加。
        }
    cout << f[n][m] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

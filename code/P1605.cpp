#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n, m, obstacles, tx, ty;
int answer = 0;
bool blocked[7][7], used[7][7];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    if (x == tx && y == ty) {
        ++answer;
        return;
    }
    used[x][y] = true; // 标记只属于当前路径。
    for (int d = 0; d < 4; ++d) {
        int u = x + dx[d], v = y + dy[d];
        if (u >= 1 && u <= n && v >= 1 && v <= m && !blocked[u][v] && !used[u][v])
            dfs(u, v);
    }
    used[x][y] = false; // 返回时让其他前缀路径能够再使用这里。
}

void solve() {
    cin >> n >> m >> obstacles;
    int sx, sy;
    cin >> sx >> sy >> tx >> ty;
    for (int i = 0; i < obstacles; ++i) {
        int x, y;
        cin >> x >> y;
        blocked[x][y] = true;
    }
    dfs(sx, sy);
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

#include <bits/stdc++.h>
using namespace std;

int n, m, obstacles, tx, ty;
long long answer = 0;
bool blocked[7][7], used[7][7];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void dfs(int x, int y) {
    if (x == tx && y == ty) { ++answer; return; }
    used[x][y] = true; // 标记只属于当前路径。
    for (int d = 0; d < 4; ++d) {
        int u = x + dx[d], v = y + dy[d];
        if (u >= 1 && u <= n && v >= 1 && v <= m && !blocked[u][v] && !used[u][v]) dfs(u, v);
    }
    used[x][y] = false; // 返回时让其他前缀路径能够再使用这里。
}

int main() {
    cin >> n >> m >> obstacles;
    int sx, sy; cin >> sx >> sy >> tx >> ty;
    for (int i = 0; i < obstacles; ++i) { int x, y; cin >> x >> y; blocked[x][y] = true; }
    dfs(sx, sy);
    cout << answer << '\n';
}

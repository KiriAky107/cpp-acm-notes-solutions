#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    vector<vector<int>> a(n + 2, vector<int>(n + 2, 0));
    vector<vector<bool>> outside(n + 2, vector<bool>(n + 2, false));
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];
    queue<pair<int,int>> q; q.emplace(0, 0); outside[0][0] = true;
    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int u = x + dx[d], v = y + dy[d];
            if (u >= 0 && u <= n + 1 && v >= 0 && v <= n + 1 && !a[u][v] && !outside[u][v]) {
                outside[u][v] = true; q.emplace(u,v); // 从外面到达的 0 保持原样。
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == 0 && !outside[i][j]) a[i][j] = 2;
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

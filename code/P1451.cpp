#include <bits/stdc++.h>
using namespace std;

bool target(char c) { return c >= '1' && c <= '9'; }

int main() {
    int n, m; cin >> n >> m;
    vector<string> a(n); for (auto& row : a) cin >> row;
    int answer = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (!target(a[i][j])) continue;
        ++answer;
        queue<pair<int,int>> q; q.emplace(i, j); a[i][j] = '.';
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int dx = -1; dx <= 1; ++dx) for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                if (abs(dx) + abs(dy) != 1) continue;
                int u = x + dx, v = y + dy;
                if (u >= 0 && u < n && v >= 0 && v < m && target(a[u][v])) {
                    a[u][v] = '.'; q.emplace(u, v); // 入队时把格子归入本块。
                }
            }
        }
    }
    cout << answer << '\n';
}

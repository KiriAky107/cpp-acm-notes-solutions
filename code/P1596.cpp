#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

bool target(char c) {
    return c == 'W';
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& row : a)
        cin >> row;
    int answer = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (!target(a[i][j]))
                continue;
            ++answer;
            queue<pair<int, int>> q;
            q.emplace(i, j);
            a[i][j] = '.';
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int dx = -1; dx <= 1; ++dx)
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 && dy == 0)
                            continue;

                        int u = x + dx, v = y + dy;
                        if (u >= 0 && u < n && v >= 0 && v < m && target(a[u][v])) {
                            a[u][v] = '.';
                            q.emplace(u, v); // 入队时把格子归入本块。
                        }
                    }
            }
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

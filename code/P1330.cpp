#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> color(n + 1, -1);
    int answer = 0;
    for (int start = 1; start <= n; ++start) {
        if (color[start] != -1)
            continue;
        int count[2] = {1, 0};
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u])
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    ++count[color[v]];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    cout << "Impossible\n";
                    return;
                } // 相邻同侧无法满足两项要求。
        }
        answer += min(count[0], count[1]);
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

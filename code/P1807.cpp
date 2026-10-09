#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<int> in(n + 1, 0);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        ++in[v];
    }
    const int neg = LLONG_MIN / 4;
    vector<int> f(n + 1, neg);
    f[1] = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (in[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : g[u]) {
            if (f[u] != neg)
                f[v] = max(f[v], f[u] + w); // 仅传递实际可达的前缀路径。
            if (--in[v] == 0)
                q.push(v);
        }
    }
    cout << (f[n] == neg ? -1 : f[n]) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

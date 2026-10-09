#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    while (m--) { int u, v; cin >> u >> v; g[u].push_back(v); }
    for (auto& row : g) sort(row.begin(), row.end());
    vector<bool> visited(n + 1, false);
    stack<int> pending; pending.push(1);
    while (!pending.empty()) {
        int u = pending.top(); pending.pop();
        if (visited[u]) continue;
        visited[u] = true; cout << u << ' ';
        for (auto it = g[u].rbegin(); it != g[u].rend(); ++it)
            if (!visited[*it]) pending.push(*it); // 反序压栈，正序访问。
    }
    cout << '\n';
    fill(visited.begin(), visited.end(), false);
    queue<int> q; q.push(1); visited[1] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); cout << u << ' ';
        for (int v : g[u]) if (!visited[v]) {
            visited[v] = true; q.push(v); // 发现时标记，同一顶点只入队一次。
        }
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

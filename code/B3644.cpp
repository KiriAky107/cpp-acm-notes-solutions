#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> in(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
        int v;
        while (cin >> v && v != 0) {
            g[u].push_back(v);
            ++in[v];
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (in[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for (int v : g[u])
            if (--in[v] == 0)
                q.push(v); // 所有前辈输出后才轮到当前人。
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

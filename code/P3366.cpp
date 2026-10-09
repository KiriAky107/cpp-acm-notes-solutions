#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    } // 路径压缩到代表节点。

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true; // 小树挂到大树，控制路径长度。
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    for (auto& [w, u, v] : edges)
        cin >> u >> v >> w;
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int answer = 0;
    int chosen = 0;
    for (auto [w, u, v] : edges)
        if (dsu.unite(u, v)) {
            answer += w;
            ++chosen;
        } // 不同组之间才加入边。
    if (chosen == n - 1)
        cout << answer << '\n';
    else
        cout << "orz\n";
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

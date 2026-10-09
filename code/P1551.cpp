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
    int n, m, q;
    cin >> n >> m >> q;
    DSU dsu(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    } // 把给定关系的两组连起来。
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (dsu.find(a) == dsu.find(b) ? "Yes" : "No") << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

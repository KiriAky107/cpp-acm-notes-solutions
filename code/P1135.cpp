#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<int> jump(n+1), dist(n+1,-1);
    for (int i=1;i<=n;++i) cin >> jump[i];
    queue<int> q; q.push(a); dist[a]=0;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int v : {u+jump[u],u-jump[u]})
            if (v>=1 && v<=n && dist[v]==-1) {
                dist[v]=dist[u]+1; q.push(v); // 首次到达这层的按键数最少。
            }
    }
    cout << dist[b] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n+1);
    for(int i=1;i<n;++i) { int u,v; cin >> u >> v; g[u].push_back(v); g[v].push_back(u); }
    vector<int> parent(n+1),depth(n+1),width(n+1,0);
    queue<int> q; q.push(1); depth[1]=1; int maxdepth=0,maxwidth=0;
    while(!q.empty()) {
        int u=q.front();q.pop(); maxdepth=max(maxdepth,depth[u]);
        maxwidth=max(maxwidth,++width[depth[u]]);
        for(int v:g[u]) if(v!=parent[u]) { parent[v]=u;depth[v]=depth[u]+1;q.push(v); }
    }
    int x,y;cin>>x>>y;int up=0,down=0;
    while(depth[x]>depth[y]) {x=parent[x];++up;}
    while(depth[y]>depth[x]) {y=parent[y];++down;}
    while(x!=y) {x=parent[x];y=parent[y];++up;++down;} // 相遇点是两条路径的共同祖先。
    cout<<maxdepth<<'\n'<<maxwidth<<'\n'<<2*up+down<<'\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

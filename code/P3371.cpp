#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n,m,s;cin>>n>>m>>s;
    vector<vector<pair<int,long long>>>g(n+1);
    while(m--){int u,v;long long w;cin>>u>>v>>w;g[u].emplace_back(v,w);}
    const long long inf=LLONG_MAX/4;vector<long long>dist(n+1,inf);dist[s]=0;
    using State=pair<long long,int>;
    priority_queue<State,vector<State>,greater<State>>heap;heap.emplace(0,s);
    while(!heap.empty()){
        auto [length,u]=heap.top();heap.pop();
        if(length!=dist[u])continue; // 跳过已被改进的旧候选。
        for(auto [v,w]:g[u])if(dist[v]>length+w){dist[v]=length+w;heap.emplace(dist[v],v);}
    }
    for(int i=1;i<=n;++i)cout<<(dist[i]==inf?2147483647LL:dist[i])<<' ';
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

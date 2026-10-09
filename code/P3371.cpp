#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
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

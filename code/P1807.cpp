#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m;cin>>n>>m;vector<vector<pair<int,int>>>g(n+1);vector<int>in(n+1,0);
    while(m--){int u,v,w;cin>>u>>v>>w;g[u].emplace_back(v,w);++in[v];}
    const long long neg=LLONG_MIN/4;vector<long long>f(n+1,neg);f[1]=0;
    queue<int>q;for(int i=1;i<=n;++i)if(in[i]==0)q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto [v,w]:g[u]){
            if(f[u]!=neg)f[v]=max(f[v],f[u]+w); // 仅传递实际可达的前缀路径。
            if(--in[v]==0)q.push(v);
        }
    }
    cout<<(f[n]==neg?-1:f[n])<<'\n';
}

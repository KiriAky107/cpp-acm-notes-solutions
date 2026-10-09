#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m;cin>>n>>m;const long long inf=LLONG_MAX/4;
    vector<vector<long long>>d(n+1,vector<long long>(n+1,inf));
    for(int i=1;i<=n;++i)d[i][i]=0;
    while(m--){int u,v;long long w;cin>>u>>v>>w;d[u][v]=d[v][u]=min(d[u][v],w);}
    for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
        if(d[i][k]!=inf&&d[k][j]!=inf)d[i][j]=min(d[i][j],d[i][k]+d[k][j]); // 放开中间点 k。
    for(int i=1;i<=n;++i){for(int j=1;j<=n;++j)cout<<d[i][j]<<' ';cout<<'\n';}
}

#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m;cin>>n>>m;
    vector<vector<int>> matrix(n+1,vector<int>(n+1,0)),g(n+1);
    while(m--){int u,v;cin>>u>>v;matrix[u][v]=matrix[v][u]=1;g[u].push_back(v);g[v].push_back(u);}
    for(int i=1;i<=n;++i){for(int j=1;j<=n;++j)cout<<matrix[i][j]<<' ';cout<<'\n';}
    for(int i=1;i<=n;++i){
        sort(g[i].begin(),g[i].end()); // 原输入顺序不一定等于邻居编号顺序。
        cout<<g[i].size();for(int v:g[i])cout<<' '<<v;cout<<'\n';
    }
}

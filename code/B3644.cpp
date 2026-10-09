#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;cin>>n;vector<vector<int>>g(n+1);vector<int>in(n+1,0);
    for(int u=1;u<=n;++u){int v;while(cin>>v&&v!=0){g[u].push_back(v);++in[v];}}
    queue<int>q;for(int i=1;i<=n;++i)if(in[i]==0)q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();cout<<u<<' ';
        for(int v:g[u])if(--in[v]==0)q.push(v); // 所有前辈输出后才轮到当前人。
    }
    cout<<'\n';
}

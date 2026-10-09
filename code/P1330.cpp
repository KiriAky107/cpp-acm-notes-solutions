#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m;cin>>n>>m;vector<vector<int>>g(n+1);
    while(m--){int u,v;cin>>u>>v;g[u].push_back(v);g[v].push_back(u);}
    vector<int> color(n+1,-1);int answer=0;
    for(int start=1;start<=n;++start){
        if(color[start]!=-1)continue;
        int count[2]={1,0};queue<int>q;q.push(start);color[start]=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:g[u]){
                if(color[v]==-1){color[v]=color[u]^1;++count[color[v]];q.push(v);}
                else if(color[v]==color[u]){cout<<"Impossible\n";return 0;} // 相邻同侧无法满足两项要求。
            }
        }
        answer+=min(count[0],count[1]);
    }
    cout<<answer<<'\n';
}

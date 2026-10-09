#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent,size;
    DSU(int n):parent(n+1),size(n+1,1){iota(parent.begin(),parent.end(),0);}
    int find(int x){return parent[x]==x?x:parent[x]=find(parent[x]);} // 路径压缩到代表节点。
    bool unite(int a,int b){
        a=find(a);b=find(b);if(a==b)return false;
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;size[a]+=size[b];return true; // 小树挂到大树，控制路径长度。
    }
};

int main() {
    int n,m;cin>>n>>m;vector<tuple<int,int,int>>edges(m);
    for(auto& [w,u,v]:edges)cin>>u>>v>>w;
    sort(edges.begin(),edges.end());DSU dsu(n);long long answer=0;int chosen=0;
    for(auto [w,u,v]:edges)if(dsu.unite(u,v)){answer+=w;++chosen;} // 不同组之间才加入边。
    if(chosen==n-1)cout<<answer<<'\n';else cout<<"orz\n";
}

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
    int n,m; cin>>n>>m;
    DSU dsu(n);
    while(m--){
        int op,a,b;cin>>op>>a>>b;
        if(op==1)dsu.unite(a,b);
        else cout<<(dsu.find(a)==dsu.find(b)?"Y":"N")<<'\n'; // 同代表表示同集合。
    }
}

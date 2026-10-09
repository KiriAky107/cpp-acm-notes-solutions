#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m,hx,hy; cin >> n >> m >> hx >> hy;
    vector<vector<bool>> blocked(n+1,vector<bool>(m+1,false));
    int dx[9]={0,1,1,-1,-1,2,2,-2,-2}, dy[9]={0,2,-2,2,-2,1,-1,1,-1};
    for (int d=0;d<9;++d) {
        int x=hx+dx[d],y=hy+dy[d];
        if(x>=0&&x<=n&&y>=0&&y<=m) blocked[x][y]=true; // 只标地图中的控制点。
    }
    vector<vector<long long>> f(n+1,vector<long long>(m+1,0));
    for(int x=0;x<=n;++x) for(int y=0;y<=m;++y) {
        if(blocked[x][y]) continue;
        if(x==0&&y==0) { f[x][y]=1; continue; }
        if(x>0) f[x][y]+=f[x-1][y];
        if(y>0) f[x][y]+=f[x][y-1]; // 两类最后一步的路径相加。
    }
    cout << f[n][m] << '\n';
}

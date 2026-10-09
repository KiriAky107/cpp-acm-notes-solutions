#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m,sx,sy; cin >> n >> m >> sx >> sy; --sx; --sy;
    vector<vector<int>> dist(n, vector<int>(m,-1));
    queue<pair<int,int>> q; q.emplace(sx,sy); dist[sx][sy]=0;
    int dx[8]={1,1,-1,-1,2,2,-2,-2}, dy[8]={2,-2,2,-2,1,-1,1,-1};
    while (!q.empty()) {
        auto [x,y]=q.front(); q.pop();
        for (int d=0;d<8;++d) {
            int u=x+dx[d], v=y+dy[d];
            if (u>=0 && u<n && v>=0 && v<m && dist[u][v]==-1) {
                dist[u][v]=dist[x][y]+1; q.emplace(u,v); // 首次发现来自最短前驱层。
            }
        }
    }
    for (auto& row : dist) { for (int x : row) cout << left << setw(5) << x; cout << '\n'; }
}

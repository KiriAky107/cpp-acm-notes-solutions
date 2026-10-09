#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, qn; cin >> n >> qn;
    vector<string> a(n); for (auto& row : a) cin >> row;
    vector<vector<int>> id(n, vector<int>(n, -1)); vector<int> sizes;
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
        if (id[i][j] != -1) continue;
        int block = sizes.size(), count = 0;
        queue<pair<int,int>> q; q.emplace(i,j); id[i][j] = block;
        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop(); ++count;
            for (int d=0;d<4;++d) {
                int u=x+dx[d], v=y+dy[d];
                if (u>=0 && u<n && v>=0 && v<n && id[u][v]==-1 && a[u][v]!=a[x][y]) {
                    id[u][v]=block; q.emplace(u,v); // 沿不同数字的边归入同一块。
                }
            }
        }
        sizes.push_back(count);
    }
    while (qn--) { int x,y; cin >> x >> y; cout << sizes[id[x-1][y-1]] << '\n'; }
}

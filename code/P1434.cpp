#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> height,memo;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int dfs(int x,int y) {
    if (memo[x][y]) return memo[x][y]; // 命中：不再展开相同子问题。
    int best=1;
    for (int d=0;d<4;++d) {
        int u=x+dx[d],v=y+dy[d];
        if (u>=0 && u<n && v>=0 && v<m && height[u][v]<height[x][y])
            best=max(best,1+dfs(u,v)); // 去掉当前格后读取子问题，再接回一格。
    }
    return memo[x][y]=best; // 邻格全部完成后，写入完整答案。
}

int main() {
    cin >> n >> m;
    height.assign(n, vector<int>(m)); memo.assign(n, vector<int>(m,0));
    for (auto& row : height) for (int& x : row) cin >> x;
    int answer=0;
    for (int x=0;x<n;++x) for (int y=0;y<m;++y) answer=max(answer,dfs(x,y));
    cout << answer << '\n';
}

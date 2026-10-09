#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
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

void solve() {
    cin >> n >> m;
    height.assign(n, vector<int>(m)); memo.assign(n, vector<int>(m,0));
    for (auto& row : height) for (int& x : row) cin >> x;
    int answer=0;
    for (int x=0;x<n;++x) for (int y=0;y<m;++y) answer=max(answer,dfs(x,y));
    cout << answer << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

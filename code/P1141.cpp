#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
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

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

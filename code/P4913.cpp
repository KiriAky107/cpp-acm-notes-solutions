#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n; cin >> n;
    vector<array<int,2>> child(n+1);
    for(int i=1;i<=n;++i) cin >> child[i][0] >> child[i][1];
    queue<pair<int,int>> q; q.emplace(1,1); int answer=0;
    while(!q.empty()) {
        auto [u,depth]=q.front(); q.pop(); answer=max(answer,depth);
        for(int v : child[u]) if(v!=0) q.emplace(v,depth+1); // 0 表示没有这个孩子。
    }
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

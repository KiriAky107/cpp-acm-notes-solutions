#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
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

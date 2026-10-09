#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, a, b; cin >> n >> a >> b;
    vector<int> jump(n+1), dist(n+1,-1);
    for (int i=1;i<=n;++i) cin >> jump[i];
    queue<int> q; q.push(a); dist[a]=0;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int v : {u+jump[u],u-jump[u]})
            if (v>=1 && v<=n && dist[v]==-1) {
                dist[v]=dist[u]+1; q.push(v); // 首次到达这层的按键数最少。
            }
    }
    cout << dist[b] << '\n';
}

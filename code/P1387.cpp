#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> f(n+1,vector<int>(m+1,0)); int answer=0;
    for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) {
        int x; cin >> x;
        if (x==1) f[i][j]=1+min({f[i-1][j],f[i][j-1],f[i-1][j-1]}); // 三块共同支撑扩张。
        answer=max(answer,f[i][j]);
    }
    cout << answer << '\n';
}

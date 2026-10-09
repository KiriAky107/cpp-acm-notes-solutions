#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m,k; string a,b; cin >> n >> m >> k >> a >> b;
    const int mod=1000000007;
    vector<vector<int>> f(m+1,vector<int>(k+1,0)),e=f;
    f[0][0]=1;
    for (int i=1;i<=n;++i) {
        vector<vector<int>> nf(m+1,vector<int>(k+1,0)),ne=nf; nf[0][0]=1;
        for(int j=1;j<=m;++j) for(int t=1;t<=k;++t) {
            if(a[i-1]==b[j-1]) ne[j][t]=(e[j-1][t]+f[j-1][t-1])%mod; // 延长，或新开一段。
            nf[j][t]=(f[j][t]+ne[j][t])%mod; // 不选当前位置，或让它成为末尾。
        }
        f.swap(nf); e.swap(ne); // 两种前驱都必须来自前一个 i。
    }
    cout << f[m][k] << '\n';
}

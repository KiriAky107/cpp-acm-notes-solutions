#include <bits/stdc++.h>
using namespace std;



int main() {
    string s; cin >> s; int n=s.size();
    vector<vector<int>> f(n,vector<int>(n,0));
    for (int length=2;length<=n;++length) for (int l=0;l+length<=n;++l) {
        int r=l+length-1;
        if (s[l]==s[r]) f[l][r]=(length==2?0:f[l+1][r-1]); // 两端直接配对。
        else f[l][r]=1+min(f[l+1][r],f[l][r-1]); // 补左端的配对字符，或补右端的配对字符。
    }
    cout << f[0][n-1] << '\n';
}

#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m; cin >> n >> m;
    vector<__int128> dp(m+1,0); dp[0]=1; // 空集合是恰好花 0 元的一种方案。
    for (int i=0;i<n;++i) {
        int price; cin >> price;
        for (int j=m;j>=price;--j) dp[j]+=dp[j-price]; // 加上选当前菜的位置集合。
    }
    cout << (long long)dp[m] << '\n';
}

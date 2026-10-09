#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,w; cin >> n >> w;
    vector<int> a(n); for (int& x : a) cin >> x;
    vector<int> dp(w+1,w+1); dp[0]=0;
    for (int s=1;s<=w;++s) for (int value : a)
        if (value<=s) dp[s]=min(dp[s],dp[s-value]+1); // 删去最后一张，再接回一张。
    cout << dp[w] << '\n';
}

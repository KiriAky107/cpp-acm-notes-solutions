#include <bits/stdc++.h>
using namespace std;



int main() {
    int capacity,n; cin >> capacity >> n;
    vector<long long> dp(capacity+1,0);
    for (int i=0;i<n;++i) {
        int cost,value;
        cin >> cost >> value;
        for (int j=capacity;j>=cost;--j)
            dp[j]=max(dp[j],dp[j-cost]+value); // 倒序读取上一轮状态，每件只用一次。
    }
    cout << dp[capacity] << '\n';
}

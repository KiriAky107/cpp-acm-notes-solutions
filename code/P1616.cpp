#include <bits/stdc++.h>
using namespace std;



int main() {
    int capacity,n; cin >> capacity >> n;
    vector<long long> dp(capacity+1,0);
    for (int i=0;i<n;++i) {
        int cost,value;
        cin >> cost >> value;
        for (int j=cost;j<=capacity;++j)
            dp[j]=max(dp[j],dp[j-cost]+value); // 读当前物品已经更新的较小容量，可继续采同种。
    }
    cout << dp[capacity] << '\n';
}

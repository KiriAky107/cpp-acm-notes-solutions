#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int capacity, n;
    cin >> capacity >> n;
    vector<int> dp(capacity + 1, 0);
    for (int i = 0; i < n; ++i) {
        int cost, value;
        cin >> cost >> value;
        for (int j = cost; j <= capacity; ++j)
            dp[j] =
                max(dp[j], dp[j - cost] + value); // 读当前物品已经更新的较小容量，可继续采同种。
    }
    cout << dp[capacity] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

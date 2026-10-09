#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<__int128> dp(m + 1, 0);
    dp[0] = 1; // 空集合是恰好花 0 元的一种方案。
    for (int i = 0; i < n; ++i) {
        int price;
        cin >> price;
        for (int j = m; j >= price; --j)
            dp[j] += dp[j - price]; // 加上选当前菜的位置集合。
    }
    cout << (int)dp[m] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

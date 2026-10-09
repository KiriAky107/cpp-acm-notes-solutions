#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n,w; cin >> n >> w;
    vector<int> a(n); for (int& x : a) cin >> x;
    vector<int> dp(w+1,w+1); dp[0]=0;
    for (int s=1;s<=w;++s) for (int value : a)
        if (value<=s) dp[s]=min(dp[s],dp[s-value]+1); // 删去最后一张，再接回一张。
    cout << dp[w] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (auto& [l, r] : intervals)
        cin >> l >> r;
    sort(intervals.begin(), intervals.end());
    int l = intervals[0].first, r = intervals[0].second, answer = 0;
    for (int i = 1; i < n; ++i) {
        auto [x, y] = intervals[i];
        if (x <= r)
            r = max(r, y); // 合并重叠或相接的段。
        else {
            answer += r - l;
            l = x;
            r = y;
        }
    }
    cout << answer + r - l << '\n'; // 结算最后一段。
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

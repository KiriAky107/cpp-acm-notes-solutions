#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (auto& [end, start] : intervals)
        cin >> start >> end;
    sort(intervals.begin(), intervals.end()); // pair 第一字段保存结束时间。
    int finish = 0, answer = 0;
    for (auto [end, start] : intervals)
        if (start >= finish) {
            ++answer;
            finish = end;
        } // 选择最早结束的可接比赛。
    cout << answer << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

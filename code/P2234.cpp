#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> history;
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (history.empty())
            answer += x; // 第一天按题目定义计入自身值。
        else {
            int best = LLONG_MAX;
            auto it = history.lower_bound(x);
            if (it != history.end())
                best = *it - x;
            if (it != history.begin())
                best = min(best, x - *prev(it));
            answer += best;
        }
        history.insert(x); // 完成当天统计后，才成为后续日期的历史。
    }
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

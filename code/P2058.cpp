#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    queue<pair<int, int>> q;
    vector<int> count(100001, 0);
    int kinds = 0;
    while (n--) {
        int time, k;
        cin >> time >> k;
        while (!q.empty() && q.front().first <= time - 86400) {
            int country = q.front().second;
            q.pop();
            if (--count[country] == 0)
                --kinds; // 该国籍的最后一个人离开窗口。
        }
        while (k--) {
            int country;
            cin >> country;
            if (count[country]++ == 0)
                ++kinds;
            q.emplace(time, country);
        }
        cout << kinds << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        q.push(i);
    while (!q.empty()) {
        int skip = (m - 1) % q.size(); // 完整绕圈不会改变队列，只移动余下的人。
        while (skip--) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ' ';
        q.pop(); // 数到 m 的人出圈。
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

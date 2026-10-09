#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> pos(n + 1), tail;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x = pos[x]; // 把数值换成它在第一个排列中的位置。
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end())
            tail.push_back(x);
        else
            *it = x; // 同长度保留更小结尾。
    }
    cout << tail.size() << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

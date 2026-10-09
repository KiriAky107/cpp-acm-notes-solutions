#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> diff(n + 2, 0);
    int last = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        diff[i] = x - last;
        last = x;
    }
    while (p--) {
        int x, y;
        int z;
        cin >> x >> y >> z;
        diff[x] += z;
        diff[y + 1] -= z;
    }
    int value = 0, answer = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        value += diff[i]; // 前缀恢复当前学生的成绩。
        answer = min(answer, value);
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

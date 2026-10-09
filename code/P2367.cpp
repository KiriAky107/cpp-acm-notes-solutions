#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n, p; cin >> n >> p;
    vector<long long> diff(n + 2, 0);
    long long last = 0;
    for (int i = 1; i <= n; ++i) { long long x; cin >> x; diff[i] = x - last; last = x; }
    while (p--) { int x, y; long long z; cin >> x >> y >> z; diff[x] += z; diff[y + 1] -= z; }
    long long value = 0, answer = LLONG_MAX;
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

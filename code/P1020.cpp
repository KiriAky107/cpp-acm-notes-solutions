#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    vector<int> tail, systems;
    int x;
    while (cin >> x) {
        auto it =
            upper_bound(tail.begin(), tail.end(), x, greater<int>()); // 非增允许相等继续延长。
        if (it == tail.end())
            tail.push_back(x);
        else
            *it = x;
        auto use = lower_bound(systems.begin(), systems.end(), x); // 最小的、仍能拦截 x 的末尾。
        if (use == systems.end())
            systems.push_back(x);
        else
            *use = x;
    }
    cout << tail.size() << '\n' << systems.size() << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

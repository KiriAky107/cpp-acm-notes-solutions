#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<long long> a(n); long long low = 0, high = 0;
    for (auto& x : a) { cin >> x; low = max(low, x); high += x; }
    auto possible = [&](long long limit) {
        int groups = 1; long long sum = 0;
        for (long long x : a) {
            if (sum + x > limit) { ++groups; sum = x; } // 当前段放不下，开始下一段。
            else sum += x;
        }
        return groups <= m;
    };
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (possible(mid)) high = mid; else low = mid + 1;
    }
    cout << low << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

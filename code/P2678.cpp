#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    long long length; int n, m; cin >> length >> n >> m;
    vector<long long> a(n); for (auto& x : a) cin >> x;
    auto possible = [&](long long distance) {
        long long last = 0; int removed = 0;
        for (long long x : a) {
            if (x - last < distance) ++removed;
            else last = x; // 保留最靠前的可行落点。
        }
        if (length - last < distance) ++removed; // 合并最后一次跳跃，移除之前的中间点。
        return removed <= m;
    };
    long long low = 0, high = length;
    while (low < high) {
        long long mid = low + (high - low + 1) / 2;
        if (possible(mid)) low = mid; else high = mid - 1;
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

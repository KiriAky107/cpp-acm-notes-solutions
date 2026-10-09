#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n; long long c; cin >> n >> c;
    vector<long long> a(n);
    map<long long, long long> count;
    for (auto& x : a) { cin >> x; ++count[x]; }
    long long answer = 0;
    for (long long x : a) {
        auto it = count.find(x - c); // 查出每个 A 能配上的 B 的位置数。
        if (it != count.end()) answer += it->second;
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

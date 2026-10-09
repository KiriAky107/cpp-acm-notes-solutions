#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n; cin >> n;
    unordered_map<long long, long long> past;
    long long answer = 0;
    while (n--) {
        long long x; cin >> x;
        for (long long p = 1; p <= (1LL << 30); p <<= 1) {
            auto it = past.find(p - x);
            if (it != past.end()) answer += it->second; // 查询范围只有此前的位置。
        }
        ++past[x]; // 查询结束后才进入历史。
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

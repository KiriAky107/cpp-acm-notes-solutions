#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    unsigned long long x;
    cin >> x;
    auto high = x >> 16; // 去掉低 16 位，读出高位部分。
    auto low = x & 65535ULL; // 掩码只保留低 16 位。
    cout << ((low << 16) | high) << '\n'; // 把低位搬到高位，再拼上原高位。
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

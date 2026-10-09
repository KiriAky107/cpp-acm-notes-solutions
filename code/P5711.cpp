#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int year;
    cin >> year;
    bool leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    cout << leap << '\n'; // bool 输出 1 或 0，对应题目要求。
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

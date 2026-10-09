#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, answer = 0;
    cin >> n;
    for (int value : {100, 20, 10, 5, 1}) {
        answer += n / value; // 取走这一面额能覆盖的整份金额。
        n %= value;          // 剩余金额交给更小面额。
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

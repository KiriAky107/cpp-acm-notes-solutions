#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    string a;
    int b;
    cin >> a >> b;
    int remainder = 0;
    string quotient;
    for (char c : a) {
        remainder = remainder * 10 + c - '0';
        quotient.push_back('0' + remainder / b); // 当前前缀产生的这一位商。
        remainder %= b;
    }
    auto first = quotient.find_first_not_of('0');
    cout << (first == string::npos ? "0" : quotient.substr(first)) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

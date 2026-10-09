#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    string s;
    cin >> s;
    stack<int> values;
    int value = 0;
    for (char c : s) {
        if (isdigit(static_cast<unsigned char>(c)))
            value = value * 10 + c - '0';
        else if (c == '.') {
            values.push(value);
            value = 0;
        } else if (c == '@')
            break;
        else {
            int right = values.top();
            values.pop(); // 后压入的是右操作数。
            int left = values.top();
            values.pop();
            if (c == '+')
                values.push(left + right);
            if (c == '-')
                values.push(left - right);
            if (c == '*')
                values.push(left * right);
            if (c == '/')
                values.push(left / right); // C++ 整数除法向 0 取整。
        }
    }
    cout << values.top() << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

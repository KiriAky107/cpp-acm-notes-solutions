#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

string add(string a, string b) {
    string result;
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int value = carry;
        if (i >= 0)
            value += a[i--] - '0';
        if (j >= 0)
            value += b[j--] - '0';
        result.push_back('0' + value % 10);
        carry = value / 10; // 保存当前位并传递进位。
    }
    reverse(result.begin(), result.end());
    return result;
}

void solve() {
    int n;
    cin >> n;
    string a = "1", b = "1"; // f(0)、f(1)。
    for (int i = 2; i <= n; ++i) {
        string c = add(a, b); // 两种最后一步的方案数量相加。
        a = b;
        b = c;
    }
    cout << b << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

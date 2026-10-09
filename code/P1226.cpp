#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    long long a, b, p; cin >> a >> b >> p;
    long long original = b, base = a % p, result = 1 % p;
    while (b > 0) {
        if (b & 1) result = result * base % p; // 选择当前二进制位对应的幂。
        base = base * base % p;
        b >>= 1; // 下一轮处理更高的指数位。
    }
    cout << a << '^' << original << " mod " << p << '=' << result << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

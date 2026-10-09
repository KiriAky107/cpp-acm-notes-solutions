#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n, value = 1;
    cin >> n;
    cout << setfill('0'); // 未满两位的数字用 0 填充。
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n - row; ++col)
            cout << setw(2) << value++; // setw 作用于紧接着的这一个数。
        cout << '\n'; // 每行长度比上一行少 1。
    }
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

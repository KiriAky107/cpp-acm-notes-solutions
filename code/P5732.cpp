#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long a[20][20] = {}; // 用零初始化整张表。
    for (int row = 0; row < n; ++row) {
        a[row][0] = a[row][row] = 1; // 每行的两端都为 1。
        for (int col = 1; col < row; ++col)
            a[row][col] = a[row - 1][col - 1] + a[row - 1][col];
        for (int col = 0; col <= row; ++col)
            cout << a[row][col] << (col == row ? '\n' : ' ');
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

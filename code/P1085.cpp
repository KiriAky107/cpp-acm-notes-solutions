#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int best = 8, day = 0;
    for (int i = 1; i <= 7; ++i) {
        int school, extra;
        cin >> school >> extra;
        if (school + extra > best) { // 只在更长时替换，保留最早的同分日。
            best = school + extra;
            day = i;
        }
    }
    cout << day << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

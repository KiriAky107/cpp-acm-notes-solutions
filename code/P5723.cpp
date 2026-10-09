#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int limit, sum = 0, count = 0;
    cin >> limit;
    for (int x = 2; x <= limit; ++x) {
        bool prime = true;
        for (int d = 2; d * d <= x; ++d)
            if (x % d == 0) { prime = false; break; } // 找到一个真因子即可结束判断。
        if (!prime) continue;
        if (sum + x > limit) break; // 按顺序放入，下一个质数只会更重。
        sum += x; ++count;
        cout << x << '\n';
    }
    cout << count << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

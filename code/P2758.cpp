#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<int> previous(m + 1), current(m + 1);
    iota(previous.begin(), previous.end(), 0);
    for (int i = 1; i <= n; ++i) {
        current[0] = i; // 把前 i 个字符全删掉。
        for (int j = 1; j <= m; ++j)
            current[j] = min({previous[j] + 1, current[j - 1] + 1,
                              previous[j - 1] + (a[i - 1] != b[j - 1])}); // 删除、插入、末尾对齐。
        swap(previous, current); // 已完成的一行成为下一轮的前驱。
    }
    cout << previous[m] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

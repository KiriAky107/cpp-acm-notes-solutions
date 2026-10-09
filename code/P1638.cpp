#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), count(m + 1, 0);
    for (int& x : a)
        cin >> x;
    int left = 0, kinds = 0, best = n + 1, x = 0, y = 0;
    for (int right = 0; right < n; ++right) {
        if (count[a[right]]++ == 0)
            ++kinds;
        while (kinds == m) {
            if (right - left + 1 < best) {
                best = right - left + 1;
                x = left;
                y = right;
            }
            if (--count[a[left++]] == 0)
                --kinds; // 缺少一种画家后停止缩小。
        }
    }
    cout << x + 1 << ' ' << y + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

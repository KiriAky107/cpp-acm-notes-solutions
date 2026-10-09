#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    deque<int> low, high;
    for (int i = 0; i < n; ++i) {
        while (!low.empty() && low.front() < i - k) low.pop_front(); // 只保留此前 k 项。
        cout << (low.empty() ? 0 : a[low.front()]) << '\n'; // 先查询，不把当前项计入。
        while (!low.empty() && a[low.back()] >= a[i]) low.pop_back();
        low.push_back(i); // 当前项供后面的查询使用。
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

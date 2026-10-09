#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    using State = tuple<int, int, int>; // 保存和、A 的位置、B 的位置。
    priority_queue<State, vector<State>, greater<State>> heap;
    for (int i = 0; i < n; ++i)
        heap.emplace(a[i] + b[0], i, 0);
    for (int k = 0; k < n; ++k) {
        auto [sum, i, j] = heap.top();
        heap.pop();
        cout << sum << ' ';
        if (j + 1 < n)
            heap.emplace(a[i] + b[j + 1], i, j + 1); // 只推进被取走的那条链。
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

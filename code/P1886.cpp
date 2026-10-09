#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a)
        cin >> x;
    deque<int> low, high;
    vector<int> minimum, maximum;
    for (int i = 0; i < n; ++i) {
        while (!low.empty() && low.front() <= i - k)
            low.pop_front();
        while (!high.empty() && high.front() <= i - k)
            high.pop_front();
        while (!low.empty() && a[low.back()] >= a[i])
            low.pop_back(); // 更大更旧的候选被支配。
        while (!high.empty() && a[high.back()] <= a[i])
            high.pop_back();
        low.push_back(i);
        high.push_back(i);
        if (i + 1 >= k) {
            minimum.push_back(a[low.front()]);
            maximum.push_back(a[high.front()]);
        }
    }
    for (int x : minimum)
        cout << x << ' ';
    cout << '\n';
    for (int x : maximum)
        cout << x << ' ';
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

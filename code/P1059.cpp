#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a)
        cin >> x;
    sort(a.begin(), a.end());                     // 先把值按从小到大排列。
    a.erase(unique(a.begin(), a.end()), a.end()); // 相邻重复值压缩后，删除末尾多余区间。
    cout << a.size() << '\n';
    for (int x : a)
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

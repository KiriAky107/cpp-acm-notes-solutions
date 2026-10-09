#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n; long long t; cin >> n >> t;
    vector<int> a(n); for (int& x : a) cin >> x;
    long long sum = 0;
    int left = 0, answer = 0;
    for (int right = 0; right < n; ++right) {
        sum += a[right];
        while (sum > t) sum -= a[left++]; // 缩小到能够读完的窗口。
        answer = max(answer, right - left + 1);
    }
    cout << answer << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    int ending = x, answer = x; // 以第一项结尾的唯一非空段。
    for (int i = 1; i < n; ++i) {
        cin >> x;
        ending = max(x, ending + x);  // 新开一段，或接到前一结尾状态。
        answer = max(answer, ending); // 全局答案还要比较不同右端点。
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

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    int c;
    cin >> n >> c;
    vector<int> a(n);
    map<int, int> count;
    for (auto& x : a) {
        cin >> x;
        ++count[x];
    }
    int answer = 0;
    for (int x : a) {
        auto it = count.find(x - c); // 查出每个 A 能配上的 B 的位置数。
        if (it != count.end())
            answer += it->second;
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

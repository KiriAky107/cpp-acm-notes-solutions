#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> past;
    int answer = 0;
    while (n--) {
        int x;
        cin >> x;
        for (int p = 1; p <= (1LL << 30); p <<= 1) {
            auto it = past.find(p - x);
            if (it != past.end())
                answer += it->second; // 查询范围只有此前的位置。
        }
        ++past[x]; // 查询结束后才进入历史。
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

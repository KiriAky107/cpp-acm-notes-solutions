#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> order(m * n);
    for (int& x : order) {
        cin >> x;
        --x;
    }
    vector<vector<int>> machine(n, vector<int>(m)), duration(n, vector<int>(m));
    for (auto& row : machine)
        for (int& x : row) {
            cin >> x;
            --x;
        }
    int total = 0;
    for (auto& row : duration)
        for (int& x : row) {
            cin >> x;
            total += x;
        }
    vector<vector<bool>> busy(m, vector<bool>(total, false));
    vector<int> next(n, 0), ready(n, 0);
    int answer = 0;
    for (int job : order) {
        int step = next[job]++, id = machine[job][step], length = duration[job][step];
        int start = ready[job];
        while (true) {
            int used = -1;
            for (int t = start; t < start + length; ++t)
                if (busy[id][t]) {
                    used = t;
                    break;
                }
            if (used == -1)
                break;        // 这一段完全空闲。
            start = used + 1; // 越过导致放不下的占用时刻。
        }
        for (int t = start; t < start + length; ++t)
            busy[id][t] = true;
        ready[job] = start + length;
        answer = max(answer, ready[job]);
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

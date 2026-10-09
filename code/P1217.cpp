#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int l, r; cin >> l >> r;
    vector<int> candidates{11};
    for (int half = 1; ; ++half) {
        long long value = half;
        for (int x = half / 10; x > 0; x /= 10) value = value * 10 + x % 10; // 镜像追加。
        if (value > r) break;
        if (value >= l) candidates.push_back((int)value);
    }
    sort(candidates.begin(), candidates.end());
    for (int x : candidates) {
        if (x < l || x > r || x < 2) continue;
        bool prime = true;
        for (int d = 2; 1LL * d * d <= x; ++d)
            if (x % d == 0) { prime = false; break; }
        if (prime) cout << x << '\n';
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

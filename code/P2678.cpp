#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int length;
    int n, m;
    cin >> length >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    auto possible = [&](int distance) {
        int last = 0;
        int removed = 0;
        for (int x : a)
            if (x - last < distance)
                ++removed;
            else
                last = x; // 保留最靠前的可行落点。
        if (length - last < distance)
            ++removed; // 合并最后一次跳跃，移除之前的中间点。
        return removed <= m;
    };
    int low = 0, high = length;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (possible(mid))
            low = mid;
        else
            high = mid - 1;
    }
    cout << low << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

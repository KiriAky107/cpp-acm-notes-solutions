#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    map<long long, long long> flowers;
    long long beauty = 0, cost = 0;
    int op;
    while (cin >> op && op != -1) {
        if (op == 1) {
            long long w, c; cin >> w >> c;
            if (flowers.emplace(c, w).second) { beauty += w; cost += c; } // 重复价格不加入。
        } else if (!flowers.empty()) {
            auto it = op == 2 ? prev(flowers.end()) : flowers.begin();
            cost -= it->first; beauty -= it->second;
            flowers.erase(it); // 总和与实际记录同步修改。
        }
    }
    cout << beauty << ' ' << cost << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

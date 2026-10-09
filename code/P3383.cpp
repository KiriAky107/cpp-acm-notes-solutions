#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<bool> composite(n + 1, false); // 位压缩存储大规模筛标记。
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (!composite[i]) primes.push_back(i);
        for (int p : primes) {
            if (p > n / i) break; // 先比较商，避免 i*p 的中间溢出。
            composite[i * p] = true;
            if (i % p == 0) break; // 每个合数只由最小质因数产生。
        }
    }
    while (q--) { int k; cin >> k; cout << primes[k - 1] << '\n'; }
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

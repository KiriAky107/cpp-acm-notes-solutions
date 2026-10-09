#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
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

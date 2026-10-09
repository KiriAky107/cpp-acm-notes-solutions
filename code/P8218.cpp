#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) { long long x; cin >> x; sum[i] = sum[i - 1] + x; }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << sum[r] - sum[l - 1] << '\n'; // 去掉左端点之前的前缀。
    }
}

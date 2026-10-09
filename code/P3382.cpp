#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; long double l, r; cin >> n >> l >> r;
    vector<long double> a(n + 1); for (auto& x : a) cin >> x;
    auto value = [&](long double x) {
        long double y = 0;
        for (long double coefficient : a) y = y * x + coefficient; // Horner 逐项求值。
        return y;
    };
    for (int step = 0; step < 200; ++step) {
        long double u = l + (r - l) / 3, v = r - (r - l) / 3;
        if (value(u) < value(v)) l = u; else r = v; // 保留含峰顶的部分。
    }
    cout << fixed << setprecision(8) << (l + r) / 2 << '\n';
}

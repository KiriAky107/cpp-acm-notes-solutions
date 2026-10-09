#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; long long need; cin >> n >> need;
    vector<long long> a(n); long long low = 0, high = 0;
    for (auto& x : a) { cin >> x; high = max(high, x); }
    while (low < high) {
        long long mid = low + (high - low + 1) / 2, wood = 0;
        for (long long x : a) if (x > mid) wood += x - mid; // 累加锯下的部分。
        if (wood >= need) low = mid; else high = mid - 1;
    }
    cout << low << '\n';
}

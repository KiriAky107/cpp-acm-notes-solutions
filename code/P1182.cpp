#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, m; cin >> n >> m;
    vector<long long> a(n); long long low = 0, high = 0;
    for (auto& x : a) { cin >> x; low = max(low, x); high += x; }
    auto possible = [&](long long limit) {
        int groups = 1; long long sum = 0;
        for (long long x : a) {
            if (sum + x > limit) { ++groups; sum = x; } // 当前段放不下，开始下一段。
            else sum += x;
        }
        return groups <= m;
    };
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (possible(mid)) high = mid; else low = mid + 1;
    }
    cout << low << '\n';
}

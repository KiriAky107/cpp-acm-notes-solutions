#include <bits/stdc++.h>
using namespace std;



int main() {
    long long length; int n, m; cin >> length >> n >> m;
    vector<long long> a(n); for (auto& x : a) cin >> x;
    auto possible = [&](long long distance) {
        long long last = 0; int removed = 0;
        for (long long x : a) {
            if (x - last < distance) ++removed;
            else last = x; // 保留最靠前的可行落点。
        }
        if (length - last < distance) ++removed; // 合并最后一次跳跃，移除之前的中间点。
        return removed <= m;
    };
    long long low = 0, high = length;
    while (low < high) {
        long long mid = low + (high - low + 1) / 2;
        if (possible(mid)) low = mid; else high = mid - 1;
    }
    cout << low << '\n';
}

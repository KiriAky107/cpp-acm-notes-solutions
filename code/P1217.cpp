#include <bits/stdc++.h>
using namespace std;



int main() {
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

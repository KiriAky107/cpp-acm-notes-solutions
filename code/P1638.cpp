#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), count(m + 1, 0);
    for (int& x : a) cin >> x;
    int left = 0, kinds = 0, best = n + 1, x = 0, y = 0;
    for (int right = 0; right < n; ++right) {
        if (count[a[right]]++ == 0) ++kinds;
        while (kinds == m) {
            if (right - left + 1 < best) { best = right - left + 1; x = left; y = right; }
            if (--count[a[left++]] == 0) --kinds; // 缺少一种画家后停止缩小。
        }
    }
    cout << x + 1 << ' ' << y + 1 << '\n';
}

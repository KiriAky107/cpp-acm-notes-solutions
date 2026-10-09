#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    vector<pair<long long,long long>> intervals(n);
    for (auto& [l, r] : intervals) cin >> l >> r;
    sort(intervals.begin(), intervals.end());
    long long l = intervals[0].first, r = intervals[0].second, answer = 0;
    for (int i = 1; i < n; ++i) {
        auto [x, y] = intervals[i];
        if (x <= r) r = max(r, y); // 合并重叠或相接的段。
        else { answer += r - l; l = x; r = y; }
    }
    cout << answer + r - l << '\n'; // 结算最后一段。
}

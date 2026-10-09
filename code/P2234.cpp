#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    set<long long> history;
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        if (history.empty()) answer += x; // 第一天按题目定义计入自身值。
        else {
            long long best = LLONG_MAX;
            auto it = history.lower_bound(x);
            if (it != history.end()) best = *it - x;
            if (it != history.begin()) best = min(best, x - *prev(it));
            answer += best;
        }
        history.insert(x); // 完成当天统计后，才成为后续日期的历史。
    }
    cout << answer << '\n';
}

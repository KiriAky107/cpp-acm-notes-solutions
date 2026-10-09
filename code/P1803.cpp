#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    vector<pair<int,int>> intervals(n);
    for (auto& [end, start] : intervals) cin >> start >> end;
    sort(intervals.begin(), intervals.end()); // pair 第一字段保存结束时间。
    int finish = 0, answer = 0;
    for (auto [end, start] : intervals)
        if (start >= finish) { ++answer; finish = end; } // 选择最早结束的可接比赛。
    cout << answer << '\n';
}

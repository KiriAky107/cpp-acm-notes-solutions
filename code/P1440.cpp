#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    deque<int> low, high;
    for (int i = 0; i < n; ++i) {
        while (!low.empty() && low.front() < i - k) low.pop_front(); // 只保留此前 k 项。
        cout << (low.empty() ? 0 : a[low.front()]) << '\n'; // 先查询，不把当前项计入。
        while (!low.empty() && a[low.back()] >= a[i]) low.pop_back();
        low.push_back(i); // 当前项供后面的查询使用。
    }
}

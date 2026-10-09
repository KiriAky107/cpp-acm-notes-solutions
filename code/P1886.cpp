#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    deque<int> low, high;
    vector<int> minimum, maximum;
    for (int i = 0; i < n; ++i) {
        while (!low.empty() && low.front() <= i - k) low.pop_front();
        while (!high.empty() && high.front() <= i - k) high.pop_front();
        while (!low.empty() && a[low.back()] >= a[i]) low.pop_back(); // 更大更旧的候选被支配。
        while (!high.empty() && a[high.back()] <= a[i]) high.pop_back();
        low.push_back(i); high.push_back(i);
        if (i + 1 >= k) { minimum.push_back(a[low.front()]); maximum.push_back(a[high.front()]); }
    }
    for (int x : minimum) cout << x << ' '; cout << '\n';
    for (int x : maximum) cout << x << ' '; cout << '\n';
}

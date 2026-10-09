#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    using State = tuple<long long, int, int>; // 保存和、A 的位置、B 的位置。
    priority_queue<State, vector<State>, greater<State>> heap;
    for (int i = 0; i < n; ++i) heap.emplace(a[i] + b[0], i, 0);
    for (int k = 0; k < n; ++k) {
        auto [sum, i, j] = heap.top(); heap.pop();
        cout << sum << ' ';
        if (j + 1 < n) heap.emplace(a[i] + b[j + 1], i, j + 1); // 只推进被取走的那条链。
    }
    cout << '\n';
}

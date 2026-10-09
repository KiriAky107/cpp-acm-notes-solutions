#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    while (q--) {
        int x; cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x); // 第一个不小于 x 的元素。
        int answer = (it != a.end() && *it == x) ? int(it - a.begin()) + 1 : -1;
        cout << answer << ' ';
    }
    cout << '\n';
}

#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end()); // 先把值按从小到大排列。
    for (int x : a) cout << x << ' ';
    cout << '\n';
}

#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; long long t; cin >> n >> t;
    vector<int> a(n); for (int& x : a) cin >> x;
    long long sum = 0;
    int left = 0, answer = 0;
    for (int right = 0; right < n; ++right) {
        sum += a[right];
        while (sum > t) sum -= a[left++]; // 缩小到能够读完的窗口。
        answer = max(answer, right - left + 1);
    }
    cout << answer << '\n';
}

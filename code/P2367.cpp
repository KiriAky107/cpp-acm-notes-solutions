#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, p; cin >> n >> p;
    vector<long long> diff(n + 2, 0);
    long long last = 0;
    for (int i = 1; i <= n; ++i) { long long x; cin >> x; diff[i] = x - last; last = x; }
    while (p--) { int x, y; long long z; cin >> x >> y >> z; diff[x] += z; diff[y + 1] -= z; }
    long long value = 0, answer = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        value += diff[i]; // 前缀恢复当前学生的成绩。
        answer = min(answer, value);
    }
    cout << answer << '\n';
}

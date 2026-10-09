#include <bits/stdc++.h>
using namespace std;



int main() {
    long long x, y; cin >> x >> y;
    if (y % x != 0) { cout << 0 << '\n'; return 0; }
    long long product = y / x, answer = 0;
    for (long long a = 1; a * a <= product; ++a) {
        if (product % a != 0) continue;
        long long b = product / a;
        if (gcd(a, b) == 1) answer += (a == b ? 1 : 2); // 还原成 P、Q 时保留两种顺序。
    }
    cout << answer << '\n';
}

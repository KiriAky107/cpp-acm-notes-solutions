#include <iostream>
using namespace std;



int main() {
    long long m, n, count[10] = {};
    cin >> m >> n;
    for (long long value = m; value <= n; ++value) {
        long long x = value; // 在副本上逐位拆数。
        do { ++count[x % 10]; x /= 10; } while (x > 0);
    }
    for (int digit = 0; digit < 10; ++digit)
        cout << count[digit] << (digit == 9 ? '\n' : ' ');
}

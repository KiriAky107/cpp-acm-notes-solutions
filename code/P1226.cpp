#include <bits/stdc++.h>
using namespace std;



int main() {
    long long a, b, p; cin >> a >> b >> p;
    long long original = b, base = a % p, result = 1 % p;
    while (b > 0) {
        if (b & 1) result = result * base % p; // 选择当前二进制位对应的幂。
        base = base * base % p;
        b >>= 1; // 下一轮处理更高的指数位。
    }
    cout << a << '^' << original << " mod " << p << '=' << result << '\n';
}

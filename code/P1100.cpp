#include <iostream>
using namespace std;



int main() {
    unsigned long long x;
    cin >> x;
    auto high = x >> 16; // 去掉低 16 位，读出高位部分。
    auto low = x & 65535ULL; // 掩码只保留低 16 位。
    cout << ((low << 16) | high) << '\n'; // 把低位搬到高位，再拼上原高位。
}

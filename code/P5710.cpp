#include <iostream>
using namespace std;



int main() {
    int x;
    cin >> x;
    bool p = (x % 2 == 0); // 第一项性质：偶数。
    bool q = (4 < x && x <= 12); // 第二项性质：大于 4 且不超过 12。
    cout << (p && q) << ' ' << (p || q) << ' '
         << (p != q) << ' ' << (!p && !q) << '\n';
}

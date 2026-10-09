#include <iostream>
using namespace std;



int main() {
    int m, t, s;
    cin >> m >> t >> s;
    if (t == 0) cout << 0 << '\n'; // 每个苹果瞬间吃完，已经没有完整苹果。
    else {
        int started = (s + t - 1) / t; // 包含正在吃的那一个。
        int left = m - started;
        cout << (left > 0 ? left : 0) << '\n';
    }
}

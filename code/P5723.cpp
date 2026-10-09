#include <iostream>
using namespace std;



int main() {
    int limit, sum = 0, count = 0;
    cin >> limit;
    for (int x = 2; x <= limit; ++x) {
        bool prime = true;
        for (int d = 2; d * d <= x; ++d)
            if (x % d == 0) { prime = false; break; } // 找到一个真因子即可结束判断。
        if (!prime) continue;
        if (sum + x > limit) break; // 按顺序放入，下一个质数只会更重。
        sum += x; ++count;
        cout << x << '\n';
    }
    cout << count << '\n';
}

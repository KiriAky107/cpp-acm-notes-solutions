#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    unordered_map<long long, long long> past;
    long long answer = 0;
    while (n--) {
        long long x; cin >> x;
        for (long long p = 1; p <= (1LL << 30); p <<= 1) {
            auto it = past.find(p - x);
            if (it != past.end()) answer += it->second; // 查询范围只有此前的位置。
        }
        ++past[x]; // 查询结束后才进入历史。
    }
    cout << answer << '\n';
}

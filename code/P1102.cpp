#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; long long c; cin >> n >> c;
    vector<long long> a(n);
    map<long long, long long> count;
    for (auto& x : a) { cin >> x; ++count[x]; }
    long long answer = 0;
    for (long long x : a) {
        auto it = count.find(x - c); // 查出每个 A 能配上的 B 的位置数。
        if (it != count.end()) answer += it->second;
    }
    cout << answer << '\n';
}

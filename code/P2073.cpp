#include <bits/stdc++.h>
using namespace std;



int main() {
    map<long long, long long> flowers;
    long long beauty = 0, cost = 0;
    int op;
    while (cin >> op && op != -1) {
        if (op == 1) {
            long long w, c; cin >> w >> c;
            if (flowers.emplace(c, w).second) { beauty += w; cost += c; } // 重复价格不加入。
        } else if (!flowers.empty()) {
            auto it = op == 2 ? prev(flowers.end()) : flowers.begin();
            cost -= it->first; beauty -= it->second;
            flowers.erase(it); // 总和与实际记录同步修改。
        }
    }
    cout << beauty << ' ' << cost << '\n';
}

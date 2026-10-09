#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    list<int> line{1};
    vector<list<int>::iterator> pos(n + 1);
    vector<bool> present(n + 1, true);
    pos[1] = line.begin();
    for (int id = 2; id <= n; ++id) {
        int k, side; cin >> k >> side;
        auto where = side == 0 ? pos[k] : next(pos[k]);
        pos[id] = line.insert(where, id); // 新迭代器保存新同学所在位置。
    }
    int m; cin >> m;
    while (m--) {
        int id; cin >> id;
        if (present[id]) { line.erase(pos[id]); present[id] = false; }
    }
    for (int id : line) cout << id << ' ';
    cout << '\n';
}

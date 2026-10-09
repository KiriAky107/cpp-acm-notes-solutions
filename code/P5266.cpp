#include <bits/stdc++.h>
using namespace std;



int main() {
    int q; cin >> q;
    map<string, int> score;
    while (q--) {
        int op; cin >> op;
        if (op == 4) { cout << score.size() << '\n'; continue; }
        string name; cin >> name;
        if (op == 1) {
            int value; cin >> value; score[name] = value;
            cout << "OK\n"; // 插入和修改都输出 OK。
        } else if (op == 2) {
            auto it = score.find(name);
            if (it == score.end()) cout << "Not found\n";
            else cout << it->second << '\n';
        } else cout << (score.erase(name) ? "Deleted successfully" : "Not found") << '\n';
    }
}

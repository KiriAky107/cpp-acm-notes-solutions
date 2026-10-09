#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int q;
    cin >> q;
    map<string, int> score;
    while (q--) {
        int op;
        cin >> op;
        if (op == 4) {
            cout << score.size() << '\n';
            continue;
        }
        string name;
        cin >> name;
        if (op == 1) {
            int value;
            cin >> value;
            score[name] = value;
            cout << "OK\n"; // 插入和修改都输出 OK。
        } else if (op == 2) {
            auto it = score.find(name);
            if (it == score.end())
                cout << "Not found\n";
            else
                cout << it->second << '\n';
        } else
            cout << (score.erase(name) ? "Deleted successfully" : "Not found") << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

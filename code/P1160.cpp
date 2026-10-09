#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    list<int> line{1};
    vector<list<int>::iterator> pos(n + 1);
    vector<bool> present(n + 1, true);
    pos[1] = line.begin();
    for (int id = 2; id <= n; ++id) {
        int k, side;
        cin >> k >> side;
        auto where = side == 0 ? pos[k] : next(pos[k]);
        pos[id] = line.insert(where, id); // 新迭代器保存新同学所在位置。
    }
    int m;
    cin >> m;
    while (m--) {
        int id;
        cin >> id;
        if (present[id]) {
            line.erase(pos[id]);
            present[id] = false;
        }
    }
    for (int id : line)
        cout << id << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

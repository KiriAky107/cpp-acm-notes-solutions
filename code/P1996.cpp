#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, m; cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; ++i) q.push(i);
    while (!q.empty()) {
        int skip = (m - 1) % q.size(); // 完整绕圈不会改变队列，只移动余下的人。
        while (skip--) { q.push(q.front()); q.pop(); }
        cout << q.front() << ' '; q.pop(); // 数到 m 的人出圈。
    }
    cout << '\n';
}

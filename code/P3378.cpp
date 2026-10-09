#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> heap;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            heap.push(x);
        }
        if (op == 2)
            cout << heap.top() << '\n'; // 最小元素处于堆顶。
        if (op == 3)
            heap.pop(); // 删除后，堆会重新选出最小元素。
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

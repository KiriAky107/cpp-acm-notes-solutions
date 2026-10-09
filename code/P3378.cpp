#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> heap;
    while (n--) {
        int op; cin >> op;
        if (op == 1) { int x; cin >> x; heap.push(x); }
        if (op == 2) cout << heap.top() << '\n'; // 最小元素处于堆顶。
        if (op == 3) heap.pop(); // 删除后，堆会重新选出最小元素。
    }
}

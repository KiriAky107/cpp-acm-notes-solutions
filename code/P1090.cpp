#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> heap;
    while (n--) { long long x; cin >> x; heap.push(x); }
    long long answer = 0;
    while (heap.size() > 1) {
        long long a = heap.top(); heap.pop();
        long long b = heap.top(); heap.pop();
        answer += a + b; heap.push(a + b); // 新堆将参加后续合并。
    }
    cout << answer << '\n';
}

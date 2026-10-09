#include <bits/stdc++.h>
using namespace std;



int main() {
    int m, n, answer = 0; cin >> m >> n;
    queue<int> q;
    bool cached[1001] = {};
    while (n--) {
        int word; cin >> word;
        if (cached[word]) continue; // 缓存命中，不改变进入顺序。
        ++answer;
        if ((int)q.size() == m) { cached[q.front()] = false; q.pop(); }
        q.push(word); cached[word] = true;
    }
    cout << answer << '\n';
}

#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    queue<pair<int,int>> q;
    vector<int> count(100001, 0);
    int kinds = 0;
    while (n--) {
        int time, k; cin >> time >> k;
        while (!q.empty() && q.front().first <= time - 86400) {
            int country = q.front().second; q.pop();
            if (--count[country] == 0) --kinds; // 该国籍的最后一个人离开窗口。
        }
        while (k--) {
            int country; cin >> country;
            if (count[country]++ == 0) ++kinds;
            q.emplace(time, country);
        }
        cout << kinds << '\n';
    }
}

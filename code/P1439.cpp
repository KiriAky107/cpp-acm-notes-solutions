#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    vector<int> pos(n+1),tail;
    for (int i=0;i<n;++i) { int x; cin >> x; pos[x]=i; }
    for (int i=0;i<n;++i) {
        int x; cin >> x; x=pos[x]; // 把数值换成它在第一个排列中的位置。
        auto it=lower_bound(tail.begin(),tail.end(),x);
        if (it==tail.end()) tail.push_back(x); else *it=x; // 同长度保留更小结尾。
    }
    cout << tail.size() << '\n';
}

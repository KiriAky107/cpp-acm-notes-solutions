#include <bits/stdc++.h>
using namespace std;



int main() {
    vector<int> tail,systems;
    int x;
    while (cin >> x) {
        auto it=upper_bound(tail.begin(),tail.end(),x,greater<int>()); // 非增允许相等继续延长。
        if (it==tail.end()) tail.push_back(x); else *it=x;
        auto use=lower_bound(systems.begin(),systems.end(),x); // 最小的、仍能拦截 x 的末尾。
        if (use==systems.end()) systems.push_back(x); else *use=x;
    }
    cout << tail.size() << '\n' << systems.size() << '\n';
}

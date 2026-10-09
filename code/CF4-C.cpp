#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    map<string, int> count;
    while (n--) {
        string name; cin >> name;
        int& seen = count[name]; // 首次访问会建立值为 0 的记录。
        if (seen == 0) cout << "OK\n";
        else cout << name << seen << '\n';
        ++seen; // 下次重复使用下一个后缀。
    }
}

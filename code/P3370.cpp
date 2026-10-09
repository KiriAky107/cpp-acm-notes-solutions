#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    unordered_set<string> words;
    while (n--) {
        string s; cin >> s;
        words.insert(s); // 容器按完整字符串的相等关系去重。
    }
    cout << words.size() << '\n';
}

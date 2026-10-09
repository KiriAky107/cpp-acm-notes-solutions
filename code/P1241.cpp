#include <bits/stdc++.h>
using namespace std;



int main() {
    string s; cin >> s;
    vector<bool> matched(s.size(), false);
    stack<int> left;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[') left.push(i);
        else if (!left.empty()) {
            char c = s[left.top()];
            if ((c == '(' && s[i] == ')') || (c == '[' && s[i] == ']')) {
                matched[i] = matched[left.top()] = true;
                left.pop(); // 只移除成功配对的左括号。
            }
        }
    }
    for (int i = 0; i < (int)s.size(); ++i)
        if (matched[i]) cout << s[i];
        else cout << ((s[i] == '(' || s[i] == ')') ? "()" : "[]");
    cout << '\n';
}

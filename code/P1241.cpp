#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
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

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

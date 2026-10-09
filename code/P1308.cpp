#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    string word, text;
    getline(cin, word); getline(cin, text); // 整行读入，保留文章中的空格。
    for (char& c : word) c = tolower(static_cast<unsigned char>(c));
    for (char& c : text) c = tolower(static_cast<unsigned char>(c));
    int count = 0, first = -1;
    for (int i = 0; i < (int)text.size();) {
        if (text[i] == ' ') { ++i; continue; }
        int start = i;
        while (i < (int)text.size() && text[i] != ' ') ++i;
        if (text.compare(start, i - start, word) == 0) { // 比较整个单词区间。
            if (first == -1) first = start;
            ++count;
        }
    }
    if (count == 0) cout << -1 << '\n';
    else cout << count << ' ' << first << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

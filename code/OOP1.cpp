#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct Student {
    int id, score;
};

void solve() {
    int n;
    cin >> n;
    vector<Student> a(n);
    for (auto& s : a)
        cin >> s.id >> s.score;
    sort(a.begin(), a.end(), [](const Student& x, const Student& y) {
        if (x.score != y.score)
            return x.score > y.score;
        return x.id < y.id; // 按两层优先级比较。
    });
    for (auto s : a)
        cout << s.id << ' ' << s.score << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

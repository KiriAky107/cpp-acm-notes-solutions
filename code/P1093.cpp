#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct Student {
    int id, chinese, total;
};

void solve() {
    int n;
    cin >> n;
    vector<Student> a(n);
    for (int i = 0; i < n; ++i) {
        int math, english;
        cin >> a[i].chinese >> math >> english;
        a[i].id = i + 1;
        a[i].total = a[i].chinese + math + english;
    }
    sort(a.begin(), a.end(), [](const Student& x, const Student& y) {
        if (x.total != y.total)
            return x.total > y.total; // 第一排序字段。
        if (x.chinese != y.chinese)
            return x.chinese > y.chinese; // 第二字段。
        return x.id < y.id;               // 同分时按学号决定先后。
    });
    for (int i = 0; i < 5; ++i)
        cout << a[i].id << ' ' << a[i].total << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

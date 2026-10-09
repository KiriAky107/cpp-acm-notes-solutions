#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
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

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

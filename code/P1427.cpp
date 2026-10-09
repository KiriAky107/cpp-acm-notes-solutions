#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    vector<int> a;
    int x;
    while (cin >> x && x != 0) a.push_back(x); // 结束标记不存入容器。
    for (auto it = a.rbegin(); it != a.rend(); ++it)
        cout << *it << ' '; // 反向迭代器从最后一个元素开始访问。
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

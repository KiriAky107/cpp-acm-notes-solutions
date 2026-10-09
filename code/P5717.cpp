#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b); // 三次比较交换把短边放在前面。
    if (a + b <= c) { cout << "Not triangle\n"; return; }
    long long s = a * a + b * b;
    if (s == c * c) cout << "Right triangle\n";
    else if (s > c * c) cout << "Acute triangle\n";
    else cout << "Obtuse triangle\n";
    if (a == b || b == c) cout << "Isosceles triangle\n"; // 边长分类继续独立判断。
    if (a == c) cout << "Equilateral triangle\n";
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

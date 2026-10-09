#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

int n, k; long long answer = 0;
vector<int> a;
bool prime(int x) {
    if (x < 2) return false;
    for (int d = 2; 1LL * d * d <= x; ++d) if (x % d == 0) return false;
    return true;
}
void dfs(int start, int chosen, int sum) {
    if (chosen == k) { if (prime(sum)) ++answer; return; }
    for (int i = start; i <= n - (k - chosen); ++i)
        dfs(i + 1, chosen + 1, sum + a[i]); // 下次只选更靠后的位置。
}

void solve() {
    cin >> n >> k; a.resize(n);
    for (int& x : a) cin >> x;
    dfs(0, 0, 0);
    cout << answer << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

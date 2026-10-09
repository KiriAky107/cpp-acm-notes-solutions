#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

int target;
array<int,10> current;
vector<array<int,10>> answers;
void dfs(int depth, int sum) {
    int left = 10 - depth;
    if (sum + left > target || sum + 3 * left < target) return; // 余下配料的总量范围。
    if (depth == 10) { answers.push_back(current); return; }
    for (int x = 1; x <= 3; ++x) {
        current[depth] = x; // 本层决定一种配料。
        dfs(depth + 1, sum + x);
    }
}

void solve() {
    cin >> target;
    dfs(0, 0);
    cout << answers.size() << '\n';
    for (const auto& choice : answers) {
        for (int x : choice) cout << x << ' ';
        cout << '\n';
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

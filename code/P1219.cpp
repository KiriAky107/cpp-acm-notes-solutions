#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

int n, position[20];
bool col[20], down[40], up[40];
long long answer = 0;
void dfs(int row) {
    if (row == n + 1) {
        ++answer;
        if (answer <= 3) {
            for (int i = 1; i <= n; ++i) cout << position[i] << ' ';
            cout << '\n';
        }
        return;
    }
    for (int c = 1; c <= n; ++c) {
        if (col[c] || down[row + c] || up[row - c + n]) continue;
        position[row] = c;
        col[c] = down[row + c] = up[row - c + n] = true; // 选择并保存当前行。
        dfs(row + 1);
        col[c] = down[row + c] = up[row - c + n] = false; // 返回后恢复进入本层时的占用状态。
    }
}

void solve() {
    cin >> n;
    dfs(1);
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

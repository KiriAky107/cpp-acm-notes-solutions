#include <bits/stdc++.h>
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

int main() {
    cin >> n;
    dfs(1);
    cout << answer << '\n';
}

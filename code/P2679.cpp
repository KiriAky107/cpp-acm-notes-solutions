#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n, m, k;
    string a, b;
    cin >> n >> m >> k >> a >> b;
    const int mod = 1000000007;
    vector<vector<int>> f(m + 1, vector<int>(k + 1, 0)), e = f;
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        vector<vector<int>> nf(m + 1, vector<int>(k + 1, 0)), ne = nf;
        nf[0][0] = 1;
        for (int j = 1; j <= m; ++j)
            for (int t = 1; t <= k; ++t) {
                if (a[i - 1] == b[j - 1])
                    ne[j][t] = (e[j - 1][t] + f[j - 1][t - 1]) % mod; // 延长，或新开一段。
                nf[j][t] = (f[j][t] + ne[j][t]) % mod; // 不选当前位置，或让它成为末尾。
            }
        f.swap(nf);
        e.swap(ne); // 两种前驱都必须来自前一个 i。
    }
    cout << f[m][k] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

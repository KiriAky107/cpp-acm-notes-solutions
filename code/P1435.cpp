#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    string s; cin >> s; int n=s.size();
    vector<vector<int>> f(n,vector<int>(n,0));
    for (int length=2;length<=n;++length) for (int l=0;l+length<=n;++l) {
        int r=l+length-1;
        if (s[l]==s[r]) f[l][r]=(length==2?0:f[l+1][r-1]); // 两端直接配对。
        else f[l][r]=1+min(f[l+1][r],f[l][r-1]); // 补左端的配对字符，或补右端的配对字符。
    }
    cout << f[0][n-1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

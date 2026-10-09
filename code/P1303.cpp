#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

void solve() {
    string a,b;cin>>a>>b;int n=a.size(),m=b.size();
    vector<long long> digit(n+m+1,0);
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)
        digit[i+j]+=1LL*(a[n-1-i]-'0')*(b[m-1-j]-'0'); // 数位位置相加。
    for(int i=0;i<n+m;++i){digit[i+1]+=digit[i]/10;digit[i]%=10;}
    int end=n+m;while(end>0&&digit[end]==0)--end;
    for(int i=end;i>=0;--i)cout<<digit[i];cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

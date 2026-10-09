#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

string add(string a,string b){
    int i=a.size()-1,j=b.size()-1,carry=0;string result;
    while(i>=0||j>=0||carry){
        int value=carry;
        if(i>=0)value+=a[i--]-'0';if(j>=0)value+=b[j--]-'0';
        result.push_back('0'+value%10);carry=value/10; // 当前位取余，高位承接进位。
    }
    reverse(result.begin(),result.end());return result;
}

void solve() {
    string a,b;cin>>a>>b;
    cout<<add(a,b)<<'\n'; // 所有数位都由字符串保存。
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

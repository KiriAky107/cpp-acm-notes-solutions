#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

string normalize(string s){
    auto p=s.find_first_not_of('0');
    return p==string::npos?"0":s.substr(p); // 保留唯一的零表示。
}

void solve() {
    string a,b;cin>>a>>b;a=normalize(a);b=normalize(b);
    bool negative=a.size()<b.size()||(a.size()==b.size()&&a<b);
    if(negative){cout<<'-';swap(a,b);} // 先确定符号，再做大数减小数。
    string result;int borrow=0,j=b.size()-1;
    for(int i=a.size()-1;i>=0;--i){
        int value=a[i]-'0'-borrow-(j>=0?b[j--]-'0':0);
        borrow=value<0;if(borrow)value+=10;
        result.push_back('0'+value); // 借位在下一轮扣除。
    }
    while(result.size()>1&&result.back()=='0')result.pop_back();
    reverse(result.begin(),result.end());cout<<result<<'\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

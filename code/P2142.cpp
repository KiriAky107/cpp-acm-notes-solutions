#include <bits/stdc++.h>
using namespace std;

string normalize(string s){
    auto p=s.find_first_not_of('0');
    return p==string::npos?"0":s.substr(p); // 保留唯一的零表示。
}

int main() {
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

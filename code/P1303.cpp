#include <bits/stdc++.h>
using namespace std;



int main() {
    string a,b;cin>>a>>b;int n=a.size(),m=b.size();
    vector<long long> digit(n+m+1,0);
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)
        digit[i+j]+=1LL*(a[n-1-i]-'0')*(b[m-1-j]-'0'); // 数位位置相加。
    for(int i=0;i<n+m;++i){digit[i+1]+=digit[i]/10;digit[i]%=10;}
    int end=n+m;while(end>0&&digit[end]==0)--end;
    for(int i=end;i>=0;--i)cout<<digit[i];cout<<'\n';
}

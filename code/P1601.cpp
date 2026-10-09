#include <bits/stdc++.h>
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

int main() {
    string a,b;cin>>a>>b;
    cout<<add(a,b)<<'\n'; // 所有数位都由字符串保存。
}

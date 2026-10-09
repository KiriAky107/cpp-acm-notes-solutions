#include <bits/stdc++.h>
using namespace std;



int main() {
    string a;long long b;cin>>a>>b;
    long long remainder=0;string quotient;
    for(char c:a){
        remainder=remainder*10+c-'0';
        quotient.push_back('0'+remainder/b); // 当前前缀产生的这一位商。
        remainder%=b;
    }
    auto first=quotient.find_first_not_of('0');
    cout<<(first==string::npos?"0":quotient.substr(first))<<'\n';
}

#include <bits/stdc++.h>
using namespace std;

string add(string a,string b) {
    string result; int i=a.size()-1,j=b.size()-1,carry=0;
    while (i>=0 || j>=0 || carry) {
        int value=carry;
        if (i>=0) value+=a[i--]-'0';
        if (j>=0) value+=b[j--]-'0';
        result.push_back('0'+value%10); carry=value/10; // 保存当前位并传递进位。
    }
    reverse(result.begin(),result.end()); return result;
}

int main() {
    int n; cin >> n;
    string a="1",b="1"; // f(0)、f(1)。
    for (int i=2;i<=n;++i) {
        string c=add(a,b); // 两种最后一步的方案数量相加。
        a=b; b=c;
    }
    cout << b << '\n';
}

#include <bits/stdc++.h>
using namespace std;



int main() {
    string a,b; cin >> a >> b; int n=a.size(),m=b.size();
    vector<int> previous(m+1),current(m+1); iota(previous.begin(),previous.end(),0);
    for (int i=1;i<=n;++i) {
        current[0]=i; // 把前 i 个字符全删掉。
        for (int j=1;j<=m;++j)
            current[j]=min({previous[j]+1,current[j-1]+1,
                            previous[j-1]+(a[i-1]!=b[j-1])}); // 删除、插入、末尾对齐。
        swap(previous,current); // 已完成的一行成为下一轮的前驱。
    }
    cout << previous[m] << '\n';
}

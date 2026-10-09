#include <bits/stdc++.h>
using namespace std;

struct Student{int id,score;};

int main() {
    int n;cin>>n;vector<Student>a(n);
    for(auto& s:a)cin>>s.id>>s.score;
    sort(a.begin(),a.end(),[](const Student& x,const Student& y){
        if(x.score!=y.score)return x.score>y.score;return x.id<y.id; // 按两层优先级比较。
    });
    for(auto s:a)cout<<s.id<<' '<<s.score<<'\n';
}

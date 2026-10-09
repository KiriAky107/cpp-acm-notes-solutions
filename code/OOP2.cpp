#include <bits/stdc++.h>
using namespace std;

class Score{
    int number=0;
public:
    bool set(int x){if(x<0||x>100)return false;number=x;return true;} // 检查通过才修改成员。
    int value()const{return number;} // 读取成绩不会改变对象。
};

int main() {
    Score score;int n;cin>>n;
    while(n--){int x;cin>>x;bool ok=score.set(x);cout<<(ok?"OK":"Rejected")<<' '<<score.value()<<'\n';}
}

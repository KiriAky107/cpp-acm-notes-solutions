#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    long long x; cin >> x;
    long long ending=x,answer=x; // 以第一项结尾的唯一非空段。
    for (int i=1;i<n;++i) {
        cin >> x;
        ending=max(x,ending+x); // 新开一段，或接到前一结尾状态。
        answer=max(answer,ending); // 全局答案还要比较不同右端点。
    }
    cout << answer << '\n';
}

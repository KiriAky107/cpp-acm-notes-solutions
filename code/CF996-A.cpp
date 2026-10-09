#include <bits/stdc++.h>
using namespace std;



int main() {
    long long n, answer = 0; cin >> n;
    for (int value : {100, 20, 10, 5, 1}) {
        answer += n / value; // 取走这一面额能覆盖的整份金额。
        n %= value; // 剩余金额交给更小面额。
    }
    cout << answer << '\n';
}

#include <bits/stdc++.h>
using namespace std;



int main() {
    long long n; cin >> n;
    int cycle[4] = {6, 8, 4, 2}; // 按正指数除以 4 的余数排列。
    cout << (n == 0 ? 1 : cycle[n % 4]) << '\n';
}

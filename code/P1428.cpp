#include <iostream>
using namespace std;



int main() {
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        int count = 0; // 只统计当前鱼左侧的鱼。
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i]) ++count;
        cout << count << (i + 1 == n ? '\n' : ' ');
    }
}

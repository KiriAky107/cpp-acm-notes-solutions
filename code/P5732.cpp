#include <iostream>
using namespace std;



int main() {
    int n;
    cin >> n;
    long long a[20][20] = {}; // 用零初始化整张表。
    for (int row = 0; row < n; ++row) {
        a[row][0] = a[row][row] = 1; // 每行的两端都为 1。
        for (int col = 1; col < row; ++col)
            a[row][col] = a[row - 1][col - 1] + a[row - 1][col];
        for (int col = 0; col <= row; ++col)
            cout << a[row][col] << (col == row ? '\n' : ' ');
    }
}

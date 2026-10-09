#include <iostream>
#include <iomanip>
using namespace std;



int main() {
    int n, value = 1;
    cin >> n;
    cout << setfill('0'); // 未满两位的数字用 0 填充。
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n - row; ++col)
            cout << setw(2) << value++; // setw 作用于紧接着的这一个数。
        cout << '\n'; // 每行长度比上一行少 1。
    }
}

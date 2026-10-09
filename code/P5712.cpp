#include <iostream>
using namespace std;



int main() {
    int x;
    cin >> x;
    cout << "Today, I ate " << x << " apple";
    if (x > 1) cout << 's'; // 多于一个时添加复数词尾。
    cout << ".\n"; // 句点也是题目要求的输出字符。
}

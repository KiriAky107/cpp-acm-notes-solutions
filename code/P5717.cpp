#include <iostream>
#include <utility>
using namespace std;



int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b); // 三次比较交换把短边放在前面。
    if (a + b <= c) { cout << "Not triangle\n"; return 0; }
    long long s = a * a + b * b;
    if (s == c * c) cout << "Right triangle\n";
    else if (s > c * c) cout << "Acute triangle\n";
    else cout << "Obtuse triangle\n";
    if (a == b || b == c) cout << "Isosceles triangle\n"; // 边长分类继续独立判断。
    if (a == c) cout << "Equilateral triangle\n";
}

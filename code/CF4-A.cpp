#include <iostream>
using namespace std;



int main() {
    int w;
    cin >> w;
    cout << (w > 2 && w % 2 == 0 ? "YES" : "NO") << '\n'; // 两项共同表达可分性。
}

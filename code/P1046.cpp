#include <iostream>
using namespace std;



int main() {
    int a[10], height, answer = 0;
    for (int i = 0; i < 10; ++i) cin >> a[i];
    cin >> height;
    for (int i = 0; i < 10; ++i)
        if (a[i] <= height + 30) ++answer; // 板凳提高了可达高度。
    cout << answer << '\n';
}

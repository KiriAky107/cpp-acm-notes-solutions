#include <iostream>
using namespace std;



int main() {
    int best = 8, day = 0;
    for (int i = 1; i <= 7; ++i) {
        int school, extra;
        cin >> school >> extra;
        if (school + extra > best) { // 只在更长时替换，保留最早的同分日。
            best = school + extra;
            day = i;
        }
    }
    cout << day << '\n';
}

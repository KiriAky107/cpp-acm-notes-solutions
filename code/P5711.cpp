#include <iostream>
using namespace std;



int main() {
    int year;
    cin >> year;
    bool leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    cout << leap << '\n'; // bool 输出 1 或 0，对应题目要求。
}

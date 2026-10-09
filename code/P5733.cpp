#include <iostream>
#include <string>
using namespace std;



int main() {
    string s;
    cin >> s;
    for (char& c : s)
        if ('a' <= c && c <= 'z') c = c - 'a' + 'A'; // 保留字母在字母表中的位置。
    cout << s << '\n';
}

#include <bits/stdc++.h>
using namespace std;



int main() {
    string s; cin >> s;
    stack<long long> values;
    long long value = 0;
    for (char c : s) {
        if (isdigit(static_cast<unsigned char>(c))) value = value * 10 + c - '0';
        else if (c == '.') { values.push(value); value = 0; }
        else if (c == '@') break;
        else {
            long long right = values.top(); values.pop(); // 后压入的是右操作数。
            long long left = values.top(); values.pop();
            if (c == '+') values.push(left + right);
            if (c == '-') values.push(left - right);
            if (c == '*') values.push(left * right);
            if (c == '/') values.push(left / right); // C++ 整数除法向 0 取整。
        }
    }
    cout << values.top() << '\n';
}

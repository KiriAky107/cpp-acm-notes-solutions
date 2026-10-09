#include <iostream>
#include <string>
#include <cctype>
using namespace std;



int main() {
    string word, text;
    getline(cin, word); getline(cin, text); // 整行读入，保留文章中的空格。
    for (char& c : word) c = tolower(static_cast<unsigned char>(c));
    for (char& c : text) c = tolower(static_cast<unsigned char>(c));
    int count = 0, first = -1;
    for (int i = 0; i < (int)text.size();) {
        if (text[i] == ' ') { ++i; continue; }
        int start = i;
        while (i < (int)text.size() && text[i] != ' ') ++i;
        if (text.compare(start, i - start, word) == 0) { // 比较整个单词区间。
            if (first == -1) first = start;
            ++count;
        }
    }
    if (count == 0) cout << -1 << '\n';
    else cout << count << ' ' << first << '\n';
}

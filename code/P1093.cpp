#include <bits/stdc++.h>
using namespace std;

struct Student { int id, chinese, total; };

int main() {
    int n;
    cin >> n;
    vector<Student> a(n);
    for (int i = 0; i < n; ++i) {
        int math, english;
        cin >> a[i].chinese >> math >> english;
        a[i].id = i + 1;
        a[i].total = a[i].chinese + math + english;
    }
    sort(a.begin(), a.end(), [](const Student& x, const Student& y) {
        if (x.total != y.total) return x.total > y.total; // 第一排序字段。
        if (x.chinese != y.chinese) return x.chinese > y.chinese; // 第二字段。
        return x.id < y.id; // 同分时按学号决定先后。
    });
    for (int i = 0; i < 5; ++i) cout << a[i].id << ' ' << a[i].total << '\n';
}

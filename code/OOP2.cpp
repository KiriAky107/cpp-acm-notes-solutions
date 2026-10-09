#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

class Score {
    int number = 0;

  public:
    bool set(int x) {
        if (x < 0 || x > 100)
            return false;
        number = x;
        return true;
    } // 检查通过才修改成员。

    int value() const {
        return number;
    } // 读取成绩不会改变对象。
};

void solve() {
    Score score;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        bool ok = score.set(x);
        cout << (ok ? "OK" : "Rejected") << ' ' << score.value() << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct Item {
    int weight, value;
};

void solve() {
    int n;
    double capacity;
    cin >> n >> capacity;
    vector<Item> a(n);
    for (auto& item : a)
        cin >> item.weight >> item.value;
    sort(a.begin(), a.end(), [](Item x, Item y) {
        return x.value * y.weight > y.value * x.weight; // 比较单位重量价值。
    });
    double answer = 0;
    for (Item item : a) {
        double taken = min(capacity, double(item.weight));
        answer += taken * item.value / item.weight;
        capacity -= taken;
        if (capacity == 0)
            break;
    }
    cout << fixed << setprecision(2) << answer << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

#include <bits/stdc++.h>
using namespace std;

struct Item { long long weight, value; };

int main() {
    int n; double capacity; cin >> n >> capacity;
    vector<Item> a(n);
    for (auto& item : a) cin >> item.weight >> item.value;
    sort(a.begin(), a.end(), [](Item x, Item y) {
        return x.value * y.weight > y.value * x.weight; // 比较单位重量价值。
    });
    double answer = 0;
    for (Item item : a) {
        double taken = min(capacity, double(item.weight));
        answer += taken * item.value / item.weight;
        capacity -= taken;
        if (capacity == 0) break;
    }
    cout << fixed << setprecision(2) << answer << '\n';
}

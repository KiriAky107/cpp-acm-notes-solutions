#include <bits/stdc++.h>
using namespace std;



int main() {
    double distance, capacity, per, initial; int n;
    cin >> distance >> capacity >> per >> initial >> n;
    vector<pair<double,double>> raw{{0, initial}, {distance, 0}};
    while (n--) { double d, p; cin >> d >> p; raw.emplace_back(d, p); }
    sort(raw.begin(), raw.end());
    vector<pair<double,double>> station;
    for (auto x : raw) {
        if (!station.empty() && abs(station.back().first - x.first) < 1e-9)
            station.back().second = min(station.back().second, x.second);
        else station.push_back(x);
    }
    if (distance == 0) { cout << "0.00\n"; return 0; }
    if (capacity == 0 || per == 0) { cout << "No Solution\n"; return 0; }
    double fuel = 0, answer = 0;
    for (int i = 0; i + 1 < (int)station.size();) {
        int cheaper = -1, cheapest = -1;
        for (int j = i + 1; j < (int)station.size(); ++j) {
            if (station[j].first - station[i].first > capacity * per + 1e-9) break;
            if (cheapest == -1 || station[j].second < station[cheapest].second) cheapest = j;
            if (station[j].second < station[i].second) { cheaper = j; break; }
        }
        if (cheapest == -1) { cout << "No Solution\n"; return 0; }
        int next = cheaper == -1 ? cheapest : cheaper;
        double required = (station[next].first - station[i].first) / per;
        double target = cheaper == -1 ? min(capacity, (distance - station[i].first) / per) : required;
        double buy = max(0.0, target - fuel); // 已有油量保留，仅补足需要的部分。
        answer += buy * station[i].second; fuel += buy - required;
        i = next;
    }
    cout << fixed << setprecision(2) << answer << '\n';
}

#include <bits/stdc++.h>
using namespace std;

int target;
array<int,10> current;
vector<array<int,10>> answers;
void dfs(int depth, int sum) {
    int left = 10 - depth;
    if (sum + left > target || sum + 3 * left < target) return; // 余下配料的总量范围。
    if (depth == 10) { answers.push_back(current); return; }
    for (int x = 1; x <= 3; ++x) {
        current[depth] = x; // 本层决定一种配料。
        dfs(depth + 1, sum + x);
    }
}

int main() {
    cin >> target;
    dfs(0, 0);
    cout << answers.size() << '\n';
    for (const auto& choice : answers) {
        for (int x : choice) cout << x << ' ';
        cout << '\n';
    }
}

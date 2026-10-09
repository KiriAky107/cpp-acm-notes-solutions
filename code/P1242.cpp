#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int pos[46], goal[46];
int moves = 0;

int towerCost(const int state[], int k, int dest) {
    if (k == 0)
        return 0;
    if (state[k] == dest)
        return towerCost(state, k - 1, dest);
    int other = 6 - state[k] - dest;
    return towerCost(state, k - 1, other) + (1LL << (k - 1)); // 收小盘、移大盘、再搬整塔。
}

void moveDisk(int k, int dest) {
    cout << "move " << k << " from " << char('A' + pos[k] - 1) << " to " << char('A' + dest - 1)
         << '\n';
    pos[k] = dest;
    ++moves;
}

void gather(int k, int dest) {
    if (k == 0)
        return;
    if (pos[k] == dest) {
        gather(k - 1, dest);
        return;
    }
    int other = 6 - pos[k] - dest;
    gather(k - 1, other);
    moveDisk(k, dest);
    gather(k - 1, dest); // 每次大盘移动前清空上方。
}

void transform(int k) {
    if (k == 0)
        return;
    if (pos[k] == goal[k]) {
        transform(k - 1);
        return;
    }
    int source = pos[k], dest = goal[k], other = 6 - source - dest;
    int direct = towerCost(pos, k - 1, other) + 1 + towerCost(goal, k - 1, other);
    int via = towerCost(pos, k - 1, dest) + (1LL << (k - 1)) + 1 + towerCost(goal, k - 1, source);
    if (direct <= via) {
        gather(k - 1, other);
        moveDisk(k, dest);
        transform(k - 1);
    } else {
        gather(k - 1, dest);
        moveDisk(k, other);
        gather(k - 1, source);
        moveDisk(k, dest);
        transform(k - 1);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int peg = 1; peg <= 3; ++peg) {
        int count;
        cin >> count;
        while (count--) {
            int disk;
            cin >> disk;
            pos[disk] = peg;
        }
    }
    for (int peg = 1; peg <= 3; ++peg) {
        int count;
        cin >> count;
        while (count--) {
            int disk;
            cin >> disk;
            goal[disk] = peg;
        }
    }
    transform(n);
    cout << moves << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

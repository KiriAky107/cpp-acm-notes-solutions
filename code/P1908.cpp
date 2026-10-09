#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

vector<int> a, temp;

int merge_count(int l, int r) {
    if (r - l <= 1)
        return 0;
    int mid = (l + r) / 2;
    int answer = merge_count(l, mid) + merge_count(mid, r);
    int i = l, j = mid, k = l;
    while (i < mid && j < r)
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else {
            answer += mid - i;
            temp[k++] = a[j++];
        } // 计入剩余左侧值构成的对。
    while (i < mid)
        temp[k++] = a[i++];
    while (j < r)
        temp[k++] = a[j++];
    copy(temp.begin() + l, temp.begin() + r, a.begin() + l);
    return answer;
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    temp.resize(n);
    for (int& x : a)
        cin >> x;
    cout << merge_count(0, n) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

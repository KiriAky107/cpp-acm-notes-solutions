#include <bits/stdc++.h>
using namespace std;

vector<int> a, temp;
long long merge_count(int l, int r) {
    if (r - l <= 1) return 0;
    int mid = (l + r) / 2;
    long long answer = merge_count(l, mid) + merge_count(mid, r);
    int i = l, j = mid, k = l;
    while (i < mid && j < r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else { answer += mid - i; temp[k++] = a[j++]; } // 计入剩余左侧值构成的对。
    }
    while (i < mid) temp[k++] = a[i++];
    while (j < r) temp[k++] = a[j++];
    copy(temp.begin() + l, temp.begin() + r, a.begin() + l);
    return answer;
}

int main() {
    int n; cin >> n;
    a.resize(n); temp.resize(n);
    for (int& x : a) cin >> x;
    cout << merge_count(0, n) << '\n';
}

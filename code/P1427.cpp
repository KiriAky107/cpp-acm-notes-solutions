#include <iostream>
#include <vector>
using namespace std;



int main() {
    vector<int> a;
    int x;
    while (cin >> x && x != 0) a.push_back(x); // 结束标记不存入容器。
    for (auto it = a.rbegin(); it != a.rend(); ++it)
        cout << *it << ' '; // 反向迭代器从最后一个元素开始访问。
    cout << '\n';
}

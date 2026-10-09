#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct Shape {
    virtual double area() const = 0;
    virtual ~Shape() = default; // 通过基类指针销毁时完成派生对象的销毁。
};

class Triangle : public Shape {
    double base, height;

  public:
    Triangle(double b, double h) : base(b), height(h) {
    }

    double area() const override {
        return base * height / 2;
    }
};

void solve() {
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Triangle>(4, 3));
    shapes.push_back(make_unique<Triangle>(6, 5));
    for (const auto& shape : shapes)
        cout << fixed << setprecision(2) << shape->area() << '\n'; // 同一接口调用不同对象。
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

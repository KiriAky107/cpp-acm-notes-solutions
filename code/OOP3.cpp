#include <bits/stdc++.h>
using namespace std;

struct Shape{
    virtual double area()const=0;
    virtual ~Shape()=default; // 通过基类指针销毁时完成派生对象的销毁。
};
class Triangle:public Shape{
    double base,height;
public:
    Triangle(double b,double h):base(b),height(h){}
    double area()const override{return base*height/2;}
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Triangle>(4,3));
    shapes.push_back(make_unique<Triangle>(6,5));
    for(const auto& shape:shapes)cout<<fixed<<setprecision(2)<<shape->area()<<'\n'; // 同一接口调用不同对象。
}

# OOP2 成绩类的修改检查

自拟练习：对应笔记面向对象部分。

对应章节：二、面向对象编程 → （九）面向对象部分的练习。

## （一） 任务与输出目标

把成绩修改集中到类的方法中，观察有效与无效输入后的对象状态。

## （二） 建模与推导

把成绩保存为私有成员，所有修改都经过 set。读到 0 到 100 的值时赋值并返回 true；其他值返回 false，成员保持之前的成绩。外部通过 value 读取，不能直接绕开修改动作。这样检查与赋值属于同一次操作。

## （三） 手算与过程

输入 80、120、60：成绩依次为 80、80、60，第二次拒绝后仍保留 80。

## （四） 带注释实现

[完整源文件](../../code/OOP2.cpp)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Score{
    int number=0;
public:
    bool set(int x){if(x<0||x>100)return false;number=x;return true;} // 检查通过才修改成员。
    int value()const{return number;} // 读取成绩不会改变对象。
};

int main() {
    Score score;int n;cin>>n;
    while(n--){int x;cin>>x;bool ok=score.set(x);cout<<(ok?"OK":"Rejected")<<' '<<score.value()<<'\n';}
}
```

头文件 `<bits/stdc++.h>` 汇总 GNU C++ 的常用标准库，包含本程序使用的流、容器与算法；这是序言竞赛模板中的包含方式。

## （五） 复杂度

每次修改 $O(1)$，对象占 $O(1)$。

[返回本章题解索引](README.md) · [返回全部题号索引](../../README.md)

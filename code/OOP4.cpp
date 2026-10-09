#include <bits/stdc++.h> // 竞赛模板中的常用标准库工具。
#define int long long   // 统一使用较大的整数类型。
#define endl '\n'       // 普通输出换行，避免逐行刷新。
using namespace std;

struct Node{
    int value;unique_ptr<Node> left,right;
    explicit Node(int x):value(x){}
};
void preorder(const Node* node){
    if(!node)return;
    cout<<node->value<<' ';preorder(node->left.get());preorder(node->right.get()); // 按根、左、右访问。
}

void solve() {
    auto root=make_unique<Node>(1);
    root->left=make_unique<Node>(2);root->right=make_unique<Node>(3); // 所有权由父节点成员持有。
    preorder(root.get());cout<<'\n'; // get 只提供访问指针，不转移所有权。
}

signed main() {
    ios::sync_with_stdio(false); // 关闭同步，使用 cin 与 cout 完成输入输出。
    cin.tie(0), cout.tie(0);

    int T = 1; // 本题读入一组数据。
    // cin >> T; // 题目给出测试组数时开启，并在 solve 中处理一组。
    while (T--)
        solve();
}

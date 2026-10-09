#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;unique_ptr<Node> left,right;
    explicit Node(int x):value(x){}
};
void preorder(const Node* node){
    if(!node)return;
    cout<<node->value<<' ';preorder(node->left.get());preorder(node->right.get()); // 按根、左、右访问。
}

int main() {
    auto root=make_unique<Node>(1);
    root->left=make_unique<Node>(2);root->right=make_unique<Node>(3); // 所有权由父节点成员持有。
    preorder(root.get());cout<<'\n'; // get 只提供访问指针，不转移所有权。
}

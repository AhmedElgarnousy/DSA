#include <iostream>

using namespace std;

struct Node
{
    // int data{};
    string data{};
    Node *right{};
    Node *left{};
    // Node(int Data) : data(Data) {}
    Node(string Data) : data(Data) {}
};

class BinaryTree
{
};

void print(Node *p)
{
    if (!p)
        return;
    print(p->right);
    print(p->left);
    cout << p->data << "\n";
}

void print_inorder(Node *node)
{ // LVR
    if (!node)
        return;
    print_inorder(node->left);
    cout << node->data << " ";
    print_inorder(node->right);
}
void print_postorder(Node *node)
{ // LRV
    if (!node)
        return;
    print_inorder(node->left);
    print_inorder(node->right);
    cout << node->data << " ";
}
void print_preorder(Node *node)
{ // VLR
    if (!node)
        return;
    cout << node->data << " ";
    print_inorder(node->left);
    print_inorder(node->right);
}
void clear(Node *node)
{
    if (!node)
        return;
    clear(node->left);
    cout << "node " << node->data << "  is free" << "\n";
    delete node;
    clear(node->right);
}

int main()
{
    // creation
    Node *multiply = new Node("*");
    Node *plus = new Node("+");
    Node *minus = new Node("-");
    Node *divide = new Node("/");
    Node *node2 = new Node("2");
    Node *node3 = new Node("3");
    Node *node9 = new Node("9");
    Node *node4 = new Node("4");
    Node *node8 = new Node("8");

    // linking
    multiply->left = plus;
    multiply->right = minus;

    plus->left = node2;
    plus->right = node3;

    minus->left = node9;
    minus->right = divide;

    divide->left = node8;
    divide->right = node4;

    // printing
    print_inorder(multiply);
    cout << "\n";
    clear(multiply);
    // print_postorder(plus);
    // cout << "\n";
    // print_preorder(plus);
    // cout << "\n";

    return 0;
}
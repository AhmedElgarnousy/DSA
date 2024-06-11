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

int main()
{
    // creation
    Node *plus = new Node("+");
    Node *node2 = new Node("2");
    Node *node3 = new Node("3");
    Node *multiply = new Node("*");
    Node *node4 = new Node("4");

    // linking
    plus->left = node2;
    plus->right = node3;

    multiply->left = plus;
    multiply->right = node4;

    // printing
    print_inorder(multiply);
    cout << "\n";
    print_postorder(plus);
    cout << "\n";
    print_preorder(plus);
    cout << "\n";

    return 0;
}
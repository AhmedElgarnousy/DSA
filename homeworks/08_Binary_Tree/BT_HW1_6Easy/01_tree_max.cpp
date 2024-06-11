
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class BinaryTree
{
private:
    int data{};
    BinaryTree *left{};
    BinaryTree *right{};

public:
    BinaryTree(int data) : data(data)
    {
    }

    void print_inorder()
    { // LVR
        if (left)
            left->print_inorder();
        cout << data << " ";
        if (right)
            right->print_inorder();
    }

    void add(vector<int> values, vector<char> direction)
    {
        assert(values.size() == direction.size());
        BinaryTree *current = this;
        // iterate on the path, create all necessary nodes
        for (int i = 0; i < (int)values.size(); i++)
        {
            if (direction[i] == 'L')
            {
                if (!current->left)
                    current->left = new BinaryTree(values[i]);
                else
                    assert(current->left->data == values[i]);
                current = current->left;
            }
            else
            {
                if (!current->right)
                    current->right = new BinaryTree(values[i]);
                else
                    assert(current->right->data == values[i]);
                current = current->right;
            }
        }
    }
    ////////////////////////////////////////////

    int tree_max()
    {
        static int right_v = 0, left_v = 0;
        static int max = 0;

        if (left)
            left_v = left->tree_max();

        if (right)
            right_v = right->tree_max();

        if (right_v > data)
            max = right_v;
        else
            max = data;

        if (left_v > max)
            max = left_v;

        cout << "max is " << max << "\n";
        return max;
    }

    ~BinaryTree()
    {
    }
};

void test1_numbers()
{
    BinaryTree tree(1);
    tree.add({2, 4, 7}, {'L', 'L', 'L'});
    tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 50, 9}, {'L', 'R', 'R'});
    tree.add({3, 6, 15}, {'R', 'R', 'L'});

    assert(tree.tree_max() == 50);
    // assert(tree.tree_height() == 3);
    // assert(tree.total_nodes() == 10);
    // assert(tree.leafs_count() == 4);

    // assert(tree.is_exists(1));
    // assert(tree.is_exists(15));
    // assert(tree.is_exists(4));
    // assert(!tree.is_exists(61));
}

int main()
{
    // BinaryTree tree(13);
    // tree.add({7}, {'L'});
    // tree.add({14}, {'R'});
    // tree.print_inorder();
    // cout << "\n";

    // BinaryTree tree(2);
    // tree.add({3}, {'L'});
    // tree.add({13, 9}, {'R', 'L'});
    // tree.add({13, 8}, {'R', 'R'});
    // tree.print_inorder();
    // cout << "\n";
    // //  3 2 7 13 8

    // cout << tree.tree_max() << " ";
    test1_numbers();
    // assert(tree.tree_max() == 13);

    return 0;
}
// https://leetcode.com/problems/path-sum/description/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct TreeNode
{ // don't copy for leetcode
    int val{};
    TreeNode *left{};
    TreeNode *right{};
    TreeNode(int val) : val(val)
    {
    }
};

struct BinaryTree
{
    TreeNode *root{};
    BinaryTree(int root_value) : root(new TreeNode(root_value))
    {
    }

    void add(vector<int> values, vector<char> direction)
    {
        assert(values.size() == direction.size());
        TreeNode *current = this->root;
        // iterate on the path, create all necessary TreeNodes
        for (int i = 0; i < (int)values.size(); ++i)
        {
            if (direction[i] == 'L')
            {
                if (!current->left)
                    current->left = new TreeNode(values[i]);
                else
                    assert(current->left->val == values[i]);
                current = current->left;
            }
            else
            {
                if (!current->right)
                    current->right = new TreeNode(values[i]);
                else
                    assert(current->right->val == values[i]);
                current = current->right;
            }
        }
    }

    void _printInorder(TreeNode *current)
    {
        if (!current)
            return;
        _printInorder(current->left);
        cout << current->val << " ";
        _printInorder(current->right);
    }

    void printInorder()
    {
        _printInorder(root);
        cout << "\n";
    }
};

bool isLeaf(TreeNode *node)
{
    return node && !node->left && !node->right;
}

class Solution
{
public:
    bool isPerfect(TreeNode *root)
    {
        if (!root->left && !root->right)
            isPerfect(root->left) && isPerfect(root->right);
        else
            return 0;
    }
};

int main()
{ // rename like main1 for leetcode
    BinaryTree tree(5);
    tree.add({4, 11, 7}, {'L', 'L', 'L'});
    tree.add({4, 11, 2}, {'L', 'L', 'R'});
    tree.add({8, 11}, {'R', 'L'});
    tree.add({8, 4, 1}, {'R', 'R', 'R'});

    // cout << Solution().hasPathSum(tree.root, 17) << "\n";
    cout << Solution().hasPathSum(tree.root, 17) << "\n";
    // cout << Solution().hasPathSum(tree.root, 170) << "\n";
    // cout << Solution().hasPathSum(tree.root, 0) << "\n";

    return 0;
}

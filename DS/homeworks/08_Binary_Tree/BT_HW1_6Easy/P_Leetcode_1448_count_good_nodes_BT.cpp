
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

int countGoodNodes(TreeNode *root, int maxSoFar)
{
    if (!root)
        return 0;

    int addme = root->val >= maxSoFar;
    int leftGoodNodes = countGoodNodes(root->left, max(root->val, maxSoFar));
    int rightGoodNodes = countGoodNodes(root->right, max(root->val, maxSoFar));

    return leftGoodNodes + rightGoodNodes + addme;
}

class Solution
{
public:
    int countGoodNodes(TreeNode *root, int maxSoFar)
    {
        if (!root)
            return 0;

        int addme = root->val >= maxSoFar;
        int leftGoodNodes = countGoodNodes(root->left, max(root->val, maxSoFar));
        int rightGoodNodes = countGoodNodes(root->right, max(root->val, maxSoFar));

        return leftGoodNodes + rightGoodNodes + addme;
    }
    int countGoodNodes(TreeNode *root)
    {
        return countGoodNodes(root, root->val);
    }
};

int main()
{
    BinaryTree tree(3);
    tree.add({1, 3}, {'L', 'L'});
    tree.add({4, 1}, {'R', 'L'});
    tree.add({4, 5}, {'R', 'R'});
    cout << Solution().countGoodNodes(tree.root) << "\n";

    return 0;
}

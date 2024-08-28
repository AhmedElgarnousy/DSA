// https://leetcode.com/problems/path-sum/description/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

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
    void level_order_traversal2()
    {
        queue<TreeNode *> nodes_queue;
        nodes_queue.push(root);

        int level = 0;
        while (!nodes_queue.empty())
        {
            int curQueueSize = nodes_queue.size();
            cout << "level " << level << ": ";
            while (curQueueSize--)
            {
                TreeNode *cur = nodes_queue.front();
                nodes_queue.pop();

                cout << cur->val << " ";
                if (cur->left)
                    nodes_queue.push(cur->left);
                if (cur->right)
                    nodes_queue.push(cur->right);
            }
            level++;
            cout << "\n";
        }
    }
};

bool isLeaf(TreeNode *node)
{
    return node && !node->left && !node->right;
}

class Solution
{
public:
    // diametere v2
};

int main()
{ // rename like main1 for leetcode
    BinaryTree tree(5);
    tree.add({4, 11}, {'L', 'L'});
    tree.add({4, 2}, {'L', 'R'});
    tree.add({8, 11}, {'R', 'L'});
    tree.add({8, 4}, {'R', 'R'});

    tree.level_order_traversal2();
    return 0;
}

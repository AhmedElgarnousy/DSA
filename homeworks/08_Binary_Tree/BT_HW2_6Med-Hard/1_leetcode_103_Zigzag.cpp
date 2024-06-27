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

    void zigzag()
    {
        deque<TreeNode *> nodes_queue;
        nodes_queue.push_front(root);

        int level = 0;
        while (!nodes_queue.empty())
        {
            int curQueueSize = nodes_queue.size();
            cout << "level " << level << ": ";
            while (curQueueSize--)
            {
                if (level % 2 == 0)
                {
                    TreeNode *cur = nodes_queue.back();
                    nodes_queue.pop_back();

                    cout << cur->val << " ";
                    if (cur->left)
                        nodes_queue.push_front(cur->left);
                    if (cur->right)
                        nodes_queue.push_front(cur->right);
                }
                else
                {
                    TreeNode *cur = nodes_queue.front();
                    nodes_queue.pop_front();

                    cout << cur->val << " ";
                    if (cur->right)
                        nodes_queue.push_back(cur->right);
                    if (cur->left)
                        nodes_queue.push_back(cur->left);
                }
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
    void zigzag()
    {
    }
};

int main()
{ // rename like main1 for leetcode
    // BinaryTree tree(5);
    // tree.add({4, 11}, {'L', 'L'});
    // tree.add({4, 2}, {'L', 'R'});
    // tree.add({8, 9}, {'R', 'L'});
    // tree.add({8, 4}, {'R', 'R'});

    BinaryTree tree(5);
    tree.add({2, 4, 10}, {'L', 'L', 'R'});
    tree.add({3, 1, 11}, {'R', 'R', 'L'});
    tree.add({3, 1, 0}, {'R', 'R', 'R'});

    tree.zigzag();
    return 0;
}

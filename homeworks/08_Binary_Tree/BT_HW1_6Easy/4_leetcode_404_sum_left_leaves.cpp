// https://leetcode.com/problems/sum-of-left-leaves/

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

class Solution
{
public:
};

int main()
{ // rename like main1 for leetcode
	BinaryTree tree(1);
	tree.add({2, 4, 7}, {'L', 'L', 'L'});
	tree.add({2, 4, 8}, {'L', 'L', 'R'});
	tree.add({2, 5, 9}, {'L', 'R', 'R'});
	tree.add({3, 6, 10}, {'R', 'R', 'L'});

	// cout << Solution().sumOfLeftLeaves(tree.root) << "\n";	// 17

	return 0;
}

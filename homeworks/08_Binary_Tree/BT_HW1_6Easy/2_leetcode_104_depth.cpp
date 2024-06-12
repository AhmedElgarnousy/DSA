// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
	int maxDepth(TreeNode *root)
	{
		int left_depth = 0, right_depth = 0;

		if (!root)
			return 0;

		left_depth = maxDepth(root->left);
		// cout << left_depth << "\n";
		right_depth = maxDepth(root->right);
		// cout << right_depth << "\n";

		return 1 + max(left_depth, right_depth);
	}
};

int main()
{ // rename like main1 for leetcode
	// BinaryTree tree(3);
	// tree.add({9}, {'L'});
	// tree.add({20, 7}, {'R', 'R'});
	// tree.add({20, 15}, {'R', 'L'});

	BinaryTree tree(1);
	tree.add({2, 4, 7}, {'L', 'L', 'L'});
	tree.add({2, 4, 8}, {'L', 'L', 'R'});
	tree.add({2, 5, 9}, {'L', 'R', 'R'});
	tree.add({3, 6, 10}, {'R', 'R', 'L'});

	cout << Solution().maxDepth(tree.root) << "\n";

	return 0;
}

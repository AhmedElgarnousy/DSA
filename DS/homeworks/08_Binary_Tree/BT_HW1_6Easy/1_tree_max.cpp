
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
	int maxValue(TreeNode *root)
	{
		if (!root)
			return 0;

		int leftMax = maxValue(root->left);
		int rightMax = maxValue(root->right);

		return max(root->val, max(leftMax, rightMax));
	}
};

int main()
{
	BinaryTree tree(1);
	// cout << Solution().maxValue(tree.root) << "\n";

	tree.add({2, 4, 70}, {'L', 'L', 'L'});
	// cout << Solution().maxValue(tree.root) << "\n";

	tree.add({2, 4, 8}, {'L', 'L', 'R'});
	// cout << Solution().maxValue(tree.root) << "\n";

	tree.add({2, 5, 9}, {'L', 'R', 'R'});
	// cout << Solution().maxValue(tree.root) << "\n";

	tree.add({3, 60, 10}, {'R', 'R', 'L'});
	cout << Solution().maxValue(tree.root) << "\n";

	return 0;
}

// int maxValue(TreeNode *root)
// if (!root)
// 			return 0;

// 		int res = root->val;
// 		if (root->left)
// 			res = max(res, maxValue(root->left));
// 		if (root->right)
// 			res = max(res, maxValue(root->right));
// 		return res;
// }

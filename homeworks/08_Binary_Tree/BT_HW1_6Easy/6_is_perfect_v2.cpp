//

#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode
{
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
		if (!root)
			return 0;

		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);

		return 1 + max(leftDepth, rightDepth);
	}

	bool isPerfect(TreeNode *root, int height)
	{
		if (isLeaf(root))
			return height == 0; // all leaves must be on the same last level

		if (!root->left && root->right || root->left && !root->right)
			return 0; // one child

		// perfect on level h is perfect on h-1 for children
		return isPerfect(root->left, height - 1) && isPerfect(root->right, height - 1);
	}

	bool isPerfect(TreeNode *root)
	{
		return isPerfect(root, maxDepth(root) - 1);
	}
};

int main()
{ // rename like main1 for leetcode
	// BinaryTree tree(1);

	// assert(Solution()._isPerfect_cnt(tree.root).first == 1);

	// tree.add({2}, {'L'});
	// assert(Solution()._isPerfect_cnt(tree.root).first == 0);

	// tree.add({3}, {'R'});
	// assert(Solution()._isPerfect_cnt(tree.root).first == 1);

	// BinaryTree tree(1);
	// tree.add({3, 6}, {'R', 'R'});
	// tree.add({3, 14}, {'R', 'L'});
	// tree.add({3, 6}, {'L', 'R'});
	// tree.add({3, 14}, {'L', 'L'});

	BinaryTree tree(5);
	tree.add({4, 11}, {'L', 'L'});
	// tree.add({4, 2}, {'L', 'R'});
	tree.add({8, 11}, {'R', 'L'});
	tree.add({8, 4}, {'R', 'R'});
	cout << Solution().isPerfect(tree.root);
	// assert(Solution()._isPerfect_cnt(tree.root).first == 0);

	// tree.add({2, 4, 7}, {'L', 'L', 'L'});
	// tree.add({2, 4, 8}, {'L', 'L', 'R'});
	// tree.add({2, 5, 9}, {'L', 'R', 'R'});
	// tree.add({3, 6, 15}, {'R', 'R', 'L'});
	// assert(Solution()._isPerfect_cnt(tree.root).first == 0);

	// tree.add({2, 5, 13}, {'L', 'R', 'L'});
	// tree.add({3, 6, 12}, {'R', 'R', 'R'});
	// assert(Solution()._isPerfect_cnt(tree.root).first == 0);

	// tree.add({3, 14, 15}, {'R', 'L', 'L'});
	// tree.add({3, 14, 16}, {'R', 'L', 'R'});

	// assert(Solution()._isPerfect_cnt(tree.root).first == 1); // now 8 leaf nodes

	// cout << "bye";

	return 0;
}

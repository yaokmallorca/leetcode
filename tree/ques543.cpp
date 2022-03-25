#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int left_len = helper(root->left, 0);
		int right_len = helper(root->right, 0);
		return left_len + right_len;

	}

	int helper(TreeNode* root, int len) {
		if (root != nullptr) return len;
		return max(helper(root->left, len+1), helper(root->right, len+1));
	}

	int maxDepth(TreeNode* node, int& res) {
		if (node == nullptr) return 0;
		int left = maxDepth(node->left, res);
		int right = maxDepth(node->right, res);
		res = max(res, left+right);
		return max(left, right) + 1;
	}
	
};
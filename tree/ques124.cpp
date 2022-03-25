#include <stdlib.h>
#include <iostream>
#include <queue>
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
	int maxPathSum(TreeNode* root) {
		int res = INT_MIN;
		maxPathSumDFS(root, res);
		return res;
	}

	int maxPathSumDFS(TreeNode* node) {
		if (node == nullptr) return 0;
		int left  = max(maxPathSumDFS(node->left, res), 0);
		int right = max(maxPathSumDFS(node->right, res), 0);
		res = max(res, node->val + left + right);
		return max(node->val + left, node->val + right);
	}
};
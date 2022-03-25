#include <stdlib.h>
#include <iostream>
#include <vector>

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
	bool isValidBST(TreeNode* root) {
		return checkBST(root, INT_MIN, INT_MAX);
	}

	bool checkBST(TreeNode* root, int mn, int mx) {
		if (!root) return true;
		if (root->val <= mn || root->val >= mx) return false;
		return checkBST(root->left, mn, root->val) && checkBST(root->right, root->val, mx);
	}
	
	bool isValidBST(TreeNode* root, long mn, long mx) {
		if (!root) return true;
		if (root->val <= mn || root->val >= mx) return false;
		return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
	}
};
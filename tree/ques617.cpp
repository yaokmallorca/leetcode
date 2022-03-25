#include <stdlib.h>
#include <iostream>
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
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		TreeNode* res = nullptr;
		mergeNodes(root1, root2, res);
		return res;
	}

	void mergeNodes(TreeNode* node1, TreeNode* node2, TreeNode*& res) {
		if (node1 == nullptr && node2 == nullptr) return;
		if (node1 != nullptr && node2 != nullptr) {
			res = new TreeNode(node1->val + node2->val);
			mergeNodes(node1->left, node2->left, res->left);
			mergeNodes(node1->right, node2->right, res->right);
		} else if (node1 != nullptr && node2 == nullptr) {
			res = new TreeNode(node1->val);
			mergeNodes(node1->left, nullptr, res->left);
			mergeNodes(node1->right, nullptr, res->right);
		} else {
			res = new TreeNode(node2->val);
			mergeNodes(nullptr, node1->left, res->left);
			mergeNodes(nullptr, node1->right,res->right);
		}
	}

};
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
	int rob(TreeNode* root) {
		int res = 0;
		unordered_map<TreeNode*, int> umap;
		robDFS(root, res, umap);
		return res;
	}

	int robDFS(TreeNode* root, unordered_map<TreeNode*, int>& umap) {
		if (root == nullptr) return 0;
		if (umap.find(root)) return umap[root];
		int val = 0;
		if (root->left != nullptr) {
			val += robDFS(root->left->right, umap) + robDFS(root->left->left, umap);
		}
		if (root->right != nullptr) {
			val += robDFS(root->right->right, umap) + robDFS(root->right->left, umap);
		}
		val += max(val + root->val, robDFS(root->left, umap) + robDFS(root->right, umap));
		umap[root] = val;
		return val;
	}
	
};
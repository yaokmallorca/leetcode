#include <stdlib.h>
#include <iostream>
#include <vector>
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
		robDFS(root, umap, res);
		return res;
	}
	
	int robDFS(TreeNode* node, unordered_map<TreeNode*, int>& umap, int& res) {
		if (node == nullptr) return 0;
		int val = 0;
		if (umap.count(node)) return umap[node];

		// rob grandson
		if (node->left != nullptr) 
			val += robDFS(node->left->left, umap, res) + robDFS(node->left->right, umap, res);
		if (node->right != nullptr) 
			val += robDFS(node->right->left, umap, res) + robDFS(node->right->right, umap, res);

		// rob son
		res = max(val+node->val, robDFS(node->left, umap, res) + robDFS(node->right, umap, res));
		umap[node] = res;
		return res;
	}
};
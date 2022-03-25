#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>

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
	TreeNode* invertTree(TreeNode* tree) {
		if (tree == nullptr) return nullptr;
		TreeNode* node = tree->left;
		tree->left = invertTree(tree->right);
		tree->right = invertTree(node);
		return tree;
	}
	
	TreeNode* invertTreeBFS(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int q_len = q.size();
			for (int i=0; i<q_len; ++i) {
				TreeNode* node = q.top(); q.pop();
				TreeNode* tmp = node->right;
				node->right = left;
				node->left = tmp;
				if (node->left != nullptr) q.push(node->left);
				if (node->right != nullptr) q.push(node->right);
			}
		}
		return root;
	}
};

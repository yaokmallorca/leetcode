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

	// left be root, right be left, root be right 
	// recursion
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		if (root == nullptr || root->left == nullptr) return root;
		TreeNode* l = root->left, *r = root->right;
		TreeNode* res = upsideDownBinaryTree(l);
		l->left = r;
		l->right = root;
		root->left = nullptr;
		root->right = nullptr;
		return res;
	}

	// iteration
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		TreeNode *cur = root, *pre = NULL, *next = NULL, *root_right = NULL;
		while (cur) {
			next = cur->left;
			cur->left = root_right;
			root_right = cur->right;
			cur->right = pre;
			pre = cur;
			cur = next;
		}
		return pre;

	}


	
};
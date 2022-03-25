#include <stdlib.h>
#include <iostream>
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
	int countNodes1(TreeNode* root) {
		if (root == nullptr) return 0;
		int res = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (que.size() > 0) {
			int n = que.size();
			for (int i = 0; i < n; ++i) {
				/* code */
				TreeNode* node = que.front(); que.pop();
				++res;
				if(node->left != nullptr) que.push(node->left);
				if(node->right != nullptr) que.push(node->right);
			}
		}
		return res;
	}

	int height(TreeNode* root) {
		if (root == nullptr) return 0;
		return 1 + height(root->left);
	}

	int countNodes(TreeNode* root) {
		if (root == nullptr) return 0;
		int res = 0;
		int height_left = height(root->left);
		int height_right = height(root->right);
		if (height_left > height_right) {
			res += pow(2, height_right);
			res += countNodes(root->left);
		} else {
			res += pow(2, height_left);
			res += countNodes(root->right);
		}
		return res;
	}
};
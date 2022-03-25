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
	// pre order: root-left-right, in order: left-root-right
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight, 
						vector<int> &inorder, int iLeft, int iRight) {
		if (pLeft > pRight || iLeft > iRight) return nullptr;
		// find the current root
		int i = pLeft;
		for (; i<pRight; ++i) {
			if (preorder[pLeft] == inorder[i]) break;
		}

		TreeNode* cur = new TreeNode(preorder[pLeft]);
		int left_subtree_len = i - iLeft;
		// split inorder, cur left is the left tree, cur right is the right tree.
		cur->left  = buildTree(preorder, pLeft+1, pLeft+left_subtree_len, inorder, iLeft, i-1);
		cur->right = buildTree(preorder, pLeft+left_subtree_len+1, pRight, inorder, i+1, iRight);
		return cur;
	}
};
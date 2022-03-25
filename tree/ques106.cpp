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
	TreeNode* buildTree(std::vector<int>& inorder, std::vector<int> postorder) {


	}

	TreeNode* buildTree(std::vector<int>& inorder, int iLeft, int iRight,
						std::vector<int>& postorder, int pLeft, int pRight) {
		if (iLeft > iRight || pLeft > pRight) return nullptr;
		// find the current root
		int i = 0;
		for (i=iLeft; i<iRight; ++i) {
			if (postorder[pRight] == inorder[i]) break;
		}
		// build the current root
		TreeNode* cur = new TreeNode(postorder[pRight]);
		int left_subtree_len = i - iLeft;
		cur->left =  buildTree(inorder, iLeft, i-1, postorder, pLeft, pRight-left_subtree_len-1);
		cur->right = buildTree(inorder, i+1, iRight, postorder, pLeft + left_subtree_len, pRight-1);
		return cur;
	}
};
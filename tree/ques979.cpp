#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	int distributeCoins(TreeNode* root) {
		int ret = 0;
		distributePost(root, ret);
		return ret;
	}

	int distributePost(TreeNode* root, int& times) {
		if (!root) return 0;
		int left = distributePost(root->left, times);
		times += abs(left);
		int right = distributePost(root->right, times);
		times += abs(right);
		return left + right + root->val - 1;
	}
	
};
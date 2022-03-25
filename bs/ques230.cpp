#include <stdlib.h>
#include <iostream>

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
	int kthSmallest(TreeNode* root, int k) {
		std::vector<int> order;
		preOrder(root, order, k);
		return order.back();
	}
	
	void preOrder(TreeNode* root, std::vector<int>& order, int k) {
		if (order.size() == k) return;
		order.push_back(root->val);
		preOrder(root->left, order, k);
		preOrder(root->right, order, k);
	}

};


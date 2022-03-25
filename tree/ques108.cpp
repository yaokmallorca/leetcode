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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int mid = nums.size() / 2;
		TreeNode* cur = new TreeNode(nums[mid]);
		std::vector<int> left(nums.begin(), nums.begin()+mid);
		std::vector<int> right(nums.begin()+mid+1, nums.end());

		cur->left = sortedArrayToBST(left);
		cur->right = sortedArrayToBST(right);
		return cur;
	}
	
};
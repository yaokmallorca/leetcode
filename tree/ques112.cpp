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
	bool hasPathSum(TreeNode* root, int targetSum) {
		std::vector<int> sums;
		int cur_sum = 0;
		PathSumDFS(root, sums, cur_sum);
		if (count(sums.begin(), sums.end(), targetSum)) return true;
		else return false;
	}
	

	void PathSumDFS(TreeNode* node, std::vector<int>& sums, int& cur_sum) {
		if (node!= nullptr) {
			cur_sum += node->val;
			if(!node->left && !node->right) sums.push_back(cur_sum);
			if (node->left) PathSumDFS(node->left, sums, cur_sum);
			if (node->right) PathSumDFS(node->right, sums, cur_sum);
			cur_sum -= node->val;
		}
	}

	void PathScanDFS(TreeNode* node, std::vector< std::vector<int> >& all_path, std::vector<int> path) {
		if (node != nullptr) {
			path.push_back(node->val);
			if (!node->left && !node->right) all_path.push_back(path);
			if (node->left) PathScanDFS(node->left, all_path, path);
			if (node->right) PathScanDFS(node->right, all_path, path);
			path.pop_back();
		}
	}
};
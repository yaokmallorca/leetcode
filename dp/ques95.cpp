#include <stdlib.h>
#include <iostream>
#include <string>
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
	std::vector< std::vector<TreeNode*> > generateTrees(int n) {
		return genTreeHelper(1, n);
	}

	std::vector<TreeNode*> genTreeHelper(int start, int end) {
		if (start > end) return {nullptr};
		std::vector<TreeNode*> res;
		for (int i = start; i < end+1; ++i) {
			/* code */
			TreeNode* cur_root = new TreeNode(i);
			std::vector<TreeNode*> cur_left_tree = genTreeHelper(start, i-1);
			std::vector<TreeNode*> cur_right_tree = genTreeHelper(i+1, end);

			// construct the current tree
			for (auto left_node : cur_left_tree) {
				for (auto right_node : cur_right_tree) {
					cur_root->left = left_node;
					cur_root->right = right_node;
					res.push_back(cur_root);
				}
			}
		}
		return res;
	}
	
};


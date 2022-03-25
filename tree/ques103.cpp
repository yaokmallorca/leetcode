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
	std::vector< std::vector<int> > zigzagLevelOrder(TreeNode* root){ 
		if (!root) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q{{root}};
		bool leftToRight = true;
		while (!q.empty()) {
			int size = q.size();
			vector<int> oneLevel(size);
			for (int i = 0; i < size; ++i) {
				TreeNode *t = q.front(); q.pop();
				int idx = leftToRight ? i : (size - 1 - i);
				oneLevel[idx] = t->val;
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			leftToRight = !leftToRight;
			res.push_back(oneLevel);
		}
		return res;
	}
	
};




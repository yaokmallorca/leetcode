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
	int minCameras(TreeNode* root) {
		int res = 0;
		return (TreeDFS(root, res) < 1 ? 1 : 0) + res;
	}

	/*
	0: uncovered
	1: covered with camera
	2: covered without camera
	*/
	int TreeDFS(TreeNode* root, int& res) {
		if (!root) return 2;
		int left 	= TreeDFS(root->left, res);
		int right	= TreeDFS(root->right, res);
		if (left == 0 || right == 0) {
			++res; return 1;
		}
		if (left == 2 && right == 2) {
			return 0;
		}
		return 2;
	}
};
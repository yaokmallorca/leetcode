#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node() : val(0), left(NULL), right(NULL), next(NULL) {}
	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
	int pathSum(TreeNode* root, int targetSum) {
		int res = 0;

	}

	void pathSumDFS(TreeNode* node, std::vector<TreeNode*>& path, std::vector< std::vector<TreeNode*> >& pathes, int targetSum, int& res) {
		if (node == nullptr) {
			pathes.push_back(path); 
			if (targetSum == 0) ++res;
			return;
		}
		if (umap[node]) return;
		path.push_back(node);
		pathSumDFS(node->left,  path, pathes, targetSum-node->val);
		pathSumDFS(node->right, path, pathes, targetSum-node->val);
		path.pop_back();
	}

	void showVec(std::vector<TreeNode*> nums) {
		for (auto num : nums) {
			cout << num->val << " ";
		}
		cout << endl;
	}

	void showVec(std::vector< std::vector<TreeNode*> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}

	void preOrder(TreeNode* root) {
		if (root == nullptr) return;
		stack<TreeNode*> st;
		TreeNode* p = root;
		while (p != nullptr || !st.empty()) {
			if (p != nullptr) {
				st.push(p);
				p = p->left;
			} else {
				p = st.top(); st.pop()
				cout << node->val << " ";
				if (p->right != nullptr) {
					p = p->right;
				}
			}
		}
		cout << endl;
	}

private:
	unordered_map<TreeNode*, bool> umap;


};
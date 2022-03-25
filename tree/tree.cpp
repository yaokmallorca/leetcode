#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// ques 102, 107, 199, 637, 429, 515, 116, 117, 104, 111

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
	// 101
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		bool res = false;
		res = isSymmetric(root->left, root->right);
		return res;
	}

	bool isSymmetric(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr) return true;
		if ((left == nullptr && right != nullptr) || 
			(left != nullptr && right == nullptr) || 
			(left->val != right->val)) {
			return false;}
		return isSymmetric(left->left, right->left) && isSymmetric(left->right, right->right);
	}

	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root->left == nullptr) return 1 + minDepth(root->right);
		if (root->right == nullptr) return 1 + minDepth(root->left);
		return 1 + min(minDepth(root->left), minDepth(root->right));
	}

	// 102 解法1 -> 队列
	std::vector< std::vector<int> > levelOrder1(TreeNode* root) {
		if (root == nullptr) return {};
		std::vector< std::vector<int> > res; 
		queue<TreeNode*> que;
		que.push(root)
		while (!que.empty()) {
			std::vector<int> one_level;
			for (int i = que.size(); i>0; --i) {
				/* code */
				TreeNode* node = que.front(); que.pop();
				one_level.push_back(node->val);
				if (node->left != nullptr) que.push(node->left);
				if (node->right != nullptr) que.push(node->right);
			}
			res.push_back(one_level);
		}
		return res;
	}

	//102 解法2 -> 递归
	std::vector< std::vector<int> > levelOrder2(TreeNode* root) {
		std::vector< std::vector<int> > res; 
		int level = 0;
		levelOrder(root, level, res);
		return res;
	}

	void levelOrder(TreeNode* root, int level, std::vector< std::vector<int> >& res) {
		if (root == nullptr) return;
		if (res.size() == level) res.push_back({});
		res[level].push_back(root->val);
		levelOrder(root->left, level+1, res);
		levelOrder(root->right, level+1, res);
	}

	int kthSmallest(TreeNode* root, int k) {
		std::vector<int> res;
		midTraverse(root, res);
		return res[k-1];
	}

	// mid traverse left->root->right
	void midTraverse(TreeNode* root, std::vector<int>& nums) {
		if (root != nullptr) {
			midTraverse(root->left, nums);
			nums.push_back(root->val);
			midTraverse(root->right, nums);
		}
	}

	// pre traverse root->left->right
	// // 1,2,#,4,#,#,3,#,#
	void preTraverse(TreeNode* root, std::vector<int>& nums) {
		if (root != nullptr) {
			nums.push_back(root->val);
			preTraverse(root->left, nums);
			preTraverse(root->right, nums);
		}
	}

	// post traverse left->right->root
	void postTraverse(TreeNode* root, std::vector<int>& nums) {
		if (root != nullptr) {
			postTraverse(root->left, nums);
			postTraverse(root->right, nums);
			nums.push_back(root->val);
		}
	}

	// left->root->right
	std::vector<int> inorderIter(TreeNode* root) {
		if (root == nullptr) return {};
		std::vector<TreeNode*> res;
		stack<TreeNode*> st;
		TreeNode* p = root;

		while(p != nullptr && !st.empty()) {
			if (p ！= nullptr) {
				// res.push_back(p);
				cout << p->val << endl;
				st.push(p);
				p = p->left;
			} else {
				p = st.top(); st.pop();
				p = p->right;
			}
		} 

	}

	TreeNode* lowestCommonAncestorBT(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || p == root || q == root) return root;
		TreeNode *left = lowestCommonAncestorBT(root->left, p, q);
		TreeNode *right = lowestCommonAncestorBT(root->right, p , q);
		if (left && right) return root;
		return left ? left : right;
	}

	TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return nullptr;
		if (root->val < min(p->val, q->val)) {
			return lowestCommonAncestorBST(root->right, p, q);
		} else (root->val > max(p->val, q->val)) {
			return lowestCommonAncestorBST(root->left, p, q);
		} else {
			return root;
		}
	}

	// root->left->right
	void preOrderIter(TreeNode* root) {
		if (root == nullptr) return;
		stack<TreeNode*> st;
		TreeNode* p = root;

		while (p != nullptr || !st.empty()) {
			if (p != nullptr) {
				st.push(p);
				p = p->left;
			} else {
				p = st.top(); st.pop();
				cout << node->val << endl;
				p = p->right;
			}

		}
	}

	// left->root->right
	void inOrderIter(TreeNode* root) {
		if (root == nullptr) return;
		stack<TreeNode*> st;
		TreeNode* p = root;
		while (p!=nullptr || !st.empty()) {
			if (p!=nullptr) {
				cout << p->val << endl;
				st.push(p);
				p = p->left;
			} else {
				p = st.top(); st.pop();
				p = p->right;
			}
		}
	}

	// left->right->root
	void postOrderIter(TreeNode* root) {
		if (root == nullptr) return;
		stack<TreeNode*> st;
		TreeNode* p = root, *prev = nullptr;

		while(p!=nullptr || !st.empty()) {
			if (p != nullptr) {
				st.push(p);
				p = p->left;
			} else {
				p = st.top();
				if (p->right != nullptr && p->right != prev) {
					p = p->right;
				} else {
					p.pop();
					cout << p->val << endl;
					prev = p;
					p = nullptr;
				}
			}
		} 
	}

	void pathSum(TreeNode* node, std::vector<TreeNode*>& path, 
		 std::vector< std::vector<TreeNode*> >& pathes,
		int cur_sum, int& res, int targetSum) {
		if (node == nullptr) return;
		cur_sum += node->val;
		path.push_back(node);
		if (cur_sum == targetSum) {
			++res;
			pathes.push_back(path);
		}
		int t = cur_sum;
		for (int i = 0; i < path.size()-1; ++i) {
			t -= path[i]->val;
			if (t == targetSum) {
				++res;
				vector<TreeNode*> tmp(path.begin()+i+1, path.end());
				pathes.push_back(tmp);
			} 
		}
		pathSum(node->left,  path, pathes, cur_sum, res, targetSum);
		pathSum(node->right, path, pathes, cur_sum, res, targetSum);
		path.pop_back();
	}

	int maxPathSumDFS(TreeNode* node, int& res) {
		if (node == nullptr) return 0;
		int left = max(maxPathSumDFS(node->left, res), 0);
		int right = max(maxPathSumDFS(node->right, res), 0);
		res = max(res, node->val + left + right);
		return max(node->val + left, node->val + right);
	}
};



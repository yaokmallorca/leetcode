#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

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
	void flatten(TreeNode* root) {
		if (root == nullptr) return nullptr;
		if (root->left != nullptr) flatten(root->left);
		if (root->right != nullptr) flatten(root->right);
		TreeNode* tmp = root->right;
		root->right = root->left;
		root->left = nullptr;
		while(root->right != nullptr) root = root->right;
		root->right = tmp;
	}

	std::vector<int> search_in_order(TreeNode* root) {
		if (root == nullptr) return {};

		std::vector<int> res;
		stack<TreeNode*> s;
		while (root != nullptr) {
			s.push(root);
			root = root->left;
		}

		while(!s.empty()) {
			auto top = s.top();
			cout << top->value << endl;
			res.push_back(top->value);
			TreeNode* t = top->right;
			s.pop();

			while(t) {
				s.push(t);
				t = t->left;
			}
		}
		return res;
	}


	std::vector<int> search_pre_order(TreeNode* root) {
		if (root == nullptr) return {};
		std::vector<int> res;
		stack<TreeNode*> s;

		while(root!=nullptr) {
			s.push(root);
			res.push_back(root->val);
			root = root->left;
		}

		while(!s.empty()) {
			auto top = s.top();
			TreeNode* node = top->right;
			s.pop();

			while(node) {
				res.push_back(node->val);
				s.push(node);
				node = node->left;
			}
		}
		return res;
	}

	std::vector<int> search_post_order(TreeNode* root) {
		if (root != nullptr) return {};
		std::vector<int> res;
		stack<TreeNode*> s;
		TreeNode* last=nullptr;

		while(root!=nullptr) {
			s.push(root);
			root = root->left;
		}
		while(!s.empty()){
			tree* top = s.top();
			if (top->left ==nullptr && top->right == nullptr ||   // 当前节点为叶子节点
				last==top->right ||						 // 前一个节点为当前节点的右子树 
				top->right==nullptr && last==top->left){ // 前一个节点为当前节点左子树且右子树为空
				printf("%d ", top->val);			// 节点pop时打印 
				res.push_back(top->val);
				last = top;						   // 记录下前一个节点
				s.pop();
			} else {
				tree* t = top->right;
				while(t){
					s.push(t);
					t = t->left;
				}
			}
		}


	}
};
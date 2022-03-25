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
	TreeNode* convertBST(TreeNode* root) {


	}

	void inorder(TreeNode* root, int& sum) {
		if (root != nullptr) {
			inorder(root->right, sum); 
			root->val += sum;
			sum = root->val;
			inorder(root->left, sum);
		}
	}

	void inorder_iter(TreeNode* root, std::vector<int>& res) {
		if (root == nullptr) return;
		stack<TreeNode*> st;
		TreeNode* p = root;

		while(p != nullptr || !st.empty()) {
			if (p != nullptr) {
				st.push(p);
				p = p->right;
			} else {
				p = st.top(); st.pop();
				res.push_back(p->val);
				p = p->left;
			}
		} 
	}

	void postorder(TreeNode* root) {
		if (root != nullptr) {
			postorder(root->right, sum); 
			postorder(root->left, sum);
			cout << root->val << endl;
		}

	}

	void preorder_iter(TreeNode* root) {
		if (root == nullptr) return;
		stack<TreeNode*> st;
		TreeNode* p;

		while (p != nullptr || !st.empty()) {
			if (p != nullptr) {
				cout << p->val << endl;
				st.push(p);
				p = p->left;
			} else {
				p = st.top();
				p = p->right;
				st.pop();
			}
		}
	}

	void postorder_iter(TreeNode* root) {
		if (root == nullptr) return;
		stack<TreeNode*> st;
		TreeNode* p, *prev = nullptr;

		while (p != nullptr || !st.empty() ) {
			if (p != nullptr) {
				cout << p->val << endl;
				st.push(p);
				p = p->left;
			} else {
				p = st.top(); st.pop();
				if (p->right != nullptr && p == prev){
					p = p->right;
				} else {
					cout << p->val << endl;
					prev = p;
				}
				
			}
		}


	}


	
};


Push p: 4
<<<<<<<<<<<<<<<<
Push p: 1
<<<<<<<<<<<<<<<<
Push p: 0
<<<<<<<<<<<<<<<<
p: 0, prev: 0
<<<<<<<<<<<<<<<<
p: 1, prev: 0
<<<<<<<<<<<<<<<<
Push p: 2
<<<<<<<<<<<<<<<<
p: 2, prev: 0
<<<<<<<<<<<<<<<<
Push p: 3

<<<<<<<<<<<<<<<<
p: 3, prev: 3

<<<<<<<<<<<<<<<<
p: 2, prev: 2

<<<<<<<<<<<<<<<<
p: 1, prev: 1
<<<<<<<<<<<<<<<<
p: 4, prev: 1
<<<<<<<<<<<<<<<<
Push p: 6
<<<<<<<<<<<<<<<<
Push p: 5
<<<<<<<<<<<<<<<<
p: 5, prev: 5
<<<<<<<<<<<<<<<<
p: 6, prev: 5
<<<<<<<<<<<<<<<<
Push p: 7
<<<<<<<<<<<<<<<<
p: 7, prev: 5
<<<<<<<<<<<<<<<<
Push p: 8
<<<<<<<<<<<<<<<<
p: 8, prev: 8
<<<<<<<<<<<<<<<<
p: 7, prev: 7
<<<<<<<<<<<<<<<<
p: 6, prev: 6
<<<<<<<<<<<<<<<<
p: 4, prev: 4
<<<<<<<<<<<<<<<<


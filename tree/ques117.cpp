#include <stdlib.h>
#include <iostream>
#include <queue>

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
	Node* connect(Node* root) {
		if (root == nullptr) return nullptr;
		queue<Node*> que;
		que.push(root);
		while(!que.empty()) {
			int n = que.size();
			for (int i = 0; i < n; ++i) {
				/* code */
				Node* node = que.front(); que.pop();
				if (i < n-1) {
					node->next = que.front();
				}
				if (node->left != nullptr) que.push(node->left);
				if (node->right != nullptr) que.push(node->right);
			}
		}
		return root;
	}
	
	Node* connect(Node* root) {
		if (root == nullptr) return nullptr;
		if (root->left != nullptr) {
			
			
		}

	}
};
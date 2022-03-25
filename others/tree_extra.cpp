#include <iostream>
#include <string>
#include <cstring> // strcmp
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <map>
#include <climits>
#include <iterator> // iterator
#include <algorithm> // reverse
#include <utility> // pair

using namespace std;

template<typename T>
class Node {
public:
	T val;
	Node *left;
	Node *right;
	Node *next;
	Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
	Node(T x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
	Node(T x, Node *left, Node *right, Node* next) : val(x), left(left), right(right), next(next) {}
};

class Solution
{
public:
	// question 116
	template<typename T>
	Node<T>* connect(Node<T>* root) {
		if (!root) return nullptr;
		if (root->left) root->left->next = root->right;
		if (root->right) root->right->next = root->next ? root->next->left : nullptr;
		connect(root->left);
		connect(root->right);
		return root;
	}

	// question 117
	template<typename T> 
	Node<T>* connectII(Node<T>* root) {
		if (!root) return nullptr;
		Node<T>* p = root->next;
		while(p) {
			if (p->left) {
				p = p->left;
				break;
			}
			if (p->right) {
				p = p->right;
				break;
			}
			p = p->next;
		}
		if (root->right) root->right->next = p; 
		if (root->left) root->left->next = root->right ? root->right : p; 
		connectII(root->right);
		connectII(root->left);
		return root;
	}

	/*
	template<typename T>
	Node<T>* connectII1(Node<T>* root) {
		Node<T>* dummy = new Node<T>(0, nullptr, nullptr, nullptr);
		Node<T>* cur = dummy, *head = root;
		while (root) {
			if (root -> left) {
				cur->next = root->left;
				cur = cur->next;
			}
			if (root->right) {
				cur->next = root->right;
				cur = cur->next;
			}
			root = root->next;
			if (!root) {
				cur = dummy;
				root = dummy->next;
				dummy->next = nullptr;
			}
		}
		return head;
	}
	*/

	template<typename T> 
	void connectNext(Node<T>* root) {
		Node<T>* dummy = new Node<T>(0, nullptr, nullptr, nullptr);
		Node<T>* cur = dummy, *head = root;
		while (root) {
			cout << "root: " << root->val << endl;
			cout << "cur: " << cur->val << endl;
			if (root -> left) {
				cur->next = root->left;
				cur = cur->next;
			}
			cout << "cur: " << cur->val << endl;
			if (root -> right) {
				cur->next = root->right;
				cur = cur->next;
			}
			cout << "cur: " << cur->val << endl;
			cout << "root:" << root->val << endl;
			cout << "dummy: " << dummy->val << endl;
			// cout << "root next: " << root->next->val << endl;
			root = root->next;
			if (!root) {
				cur = dummy;
				root = dummy->next;
				dummy->next = nullptr;
			}
			cout << "<<<<<<<<<<<<<<<<<<<<<<" << endl;
		}
	}

	template<typename T>
	void PreOrder(Node<T>* node) {
		if (!node) {
			cout << node->val << " ";
			PreOrder(node->left);
			PreOrder(node->right);
		}
	}
};


int main () {
	Solution s;

	Node<int>* root = new Node<int>(1);
	root->left = new Node<int>(2);
	root->right = new Node<int>(3);
	root->left->left = new Node<int>(4);
	root->left->right = new Node<int>(5);
	root->right->right = new Node<int>(6);

	s.connectNext(root);



}	
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
struct TreeNode {
	T val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(T x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template<typename T>
struct ListNode 
{
	T val;
	ListNode * next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(T x) : val(x), next(nullptr) {}
	ListNode(T x, ListNode* pnext) : val(x), next(pnext) {}
};

class Solution
{
public:
	template<typename T>
	void BreadthFirst(TreeNode<T>* root) {
		std::queue<TreeNode<T>*> nodeQue;
		nodeQue.push(root);
		TreeNode<T> *node;
		while(!nodeQue.empty()) {
			node = nodeQue.front();
			nodeQue.pop();
			cout << node->val << endl;
			if (node->left != nullptr) {
				nodeQue.push(node->left);
			}
			if (node->right != nullptr) {
				nodeQue.push(node->right);
			}
		}

	}
	
	void showVec(std::vector< std::vector<int> >& nums) {
		for (auto vec : nums) {
			showVec(vec);
		}
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	template<typename T>
	TreeNode<T>* insertTreeNode(int val) {
		TreeNode<T>* node = new TreeNode<T>(val);
		return node;
	}

	template<typename T>
	void PreOrder(TreeNode<T>* node) {
		if (node != nullptr) {
			cout << node->val << " ";
			PreOrder(node->left);
			PreOrder(node->right);
		}
	}

	template<typename T>
	void InOrder(TreeNode<T>* node) {
		if (node != nullptr) {
			InOrder(node->left);
			cout << node->val << " ";
			InOrder(node->right);
		}
	}

	template<typename T>
	void PostOrder(TreeNode<T>* node) {
		if (node != nullptr) {
			PostOrder(node->left);
			PostOrder(node->right);
			cout << node->val << " ";
		}
	}

	template<typename T>
	TreeNode<T>* initBTree(std::vector<T> nums) {
		if (nums.size() == 0) return nullptr;
		int m = nums.size();
		TreeNode<T>* root = new TreeNode<T>(nums[0]);
		TreeNode<T>* node = root;
		int i = 1;
		while(i<m) {
			cout << "node: " << node->val << endl;
			if (nums[i] != INT_MIN && node) {
				TreeNode<T>* tmp = new TreeNode<T>(nums[i]);
				node->left = tmp;
			}
			++i;
			if (nums[i] != INT_MIN) {
				TreeNode<T>* tmp = new TreeNode<T>(nums[i]);
				node->right = tmp;
			}
			++i;
			if (node->left != nullptr) {
				cout << "leaf: " << node->left->val << " " << node->right->val << endl;
				node = node->left;
				cout << "i = " << i << endl;
				continue;
			}
			if (node->right != nullptr) {
				cout << "leaf: " << node->left->val << " " << node->right->val << endl;
				node = node->right;
			}
			cout << "i = " << i << endl;
		}
		return root;
	}

	
	template<typename T>
	std::vector< std::vector<int> > zigzagLevelOrder(TreeNode<T>* tree) {
		if (tree == nullptr) return {};
		std::vector< std::vector<int> > res;
		queue<TreeNode<T>*> nodeQue;
		nodeQue.push({tree});
		int cnt = 1;
		while (!nodeQue.empty()) {
			std::vector<int> oneLayer;
			for (int i = nodeQue.size(); i>0; --i) {
				TreeNode<T>* node = nodeQue.front(); nodeQue.pop();
				oneLayer.push_back(node->val);
				if (node->left) nodeQue.push(node->left);
				if (node->right) nodeQue.push(node->right);
			}
			if (cnt%2 == 0) reverse(oneLayer.begin(), oneLayer.end());
			res.push_back(oneLayer);
			++cnt;
		}
		return res;
	}

	template<typename T>
	TreeNode<T>* buildTree(std::vector<T> preorder, std::vector<T> inorder) {
		if (preorder.empty() && inorder.empty()) return nullptr;
		TreeNode<T>* cur = new TreeNode<T>(preorder[0]);
		int i=0;
		for(;i<inorder.size(); ++i) {
			if (inorder[i] == preorder[0]) break;
		}
		std::vector<T> pre_left(preorder.begin()+1, preorder.begin()+1+i);
		std::vector<T> pre_right(preorder.begin()+i+1, preorder.end());
		std::vector<T> in_left(inorder.begin(), inorder.begin()+i);
		std::vector<T> in_right(inorder.begin()+i+1, inorder.end());
		cur->left = buildTree(pre_left, in_left);
		cur->right = buildTree(pre_right, in_right);
		return cur;
	}

	template<typename T> 
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	/*
	template<typename T>
	TreeNode<T>* buildTreePost(std::vector<T> post_order, std::vector<T> in_order) {
		if (post_order.empty() && in_order.empty()) return NULL;
		int p = post_order.size()-1;
		TreeNode<T>* cur = new TreeNode<T>(post_order[p]);
		int i = 0;
		for(;i<in_order.size();++i) {
			if (in_order[i] == post_order[p]) {break;}
		}
		std::vector<T> post_left(post_order.begin(), post_order.begin()+i);
		std::vector<T> post_right(post_order.begin()+i, post_order.end()-1);
		std::vector<T> in_left(in_order.begin(), in_order.begin()+i);
		std::vector<T> in_right(in_order.begin()+i+1, in_order.end());

		cur->left 	= buildTreePost(post_left, in_left);
		cur->right 	= buildTreePost(post_right, in_right);
		return cur; 
	}
	*/

	template<typename T>
	TreeNode<T>* buildTreePost(std::vector<T>& in_order, std::vector<T> post_order) {
		return buildTreePost(in_order, 0, in_order.size()-1, post_order, 0, post_order.size()-1);
	}

	template<typename T>
	TreeNode<T>* buildTreePost(std::vector<T> in_order, int ileft, int iright, 
					   std::vector<T> post_order, int pleft, int pright) {
		if (ileft > iright || pleft > pright) {return nullptr;}
		TreeNode<T>* cur = new TreeNode<T>(post_order[pright]);
		int i = 0;
		for (i = ileft; i<iright; ++i) {
			if (in_order[i] == post_order[pright]) break;
		}
		cur->left = buildTreePost(in_order, ileft, i-1, post_order, pleft, pleft+i-ileft-1);
		cur->right = buildTreePost(in_order, i+1, iright, post_order, pleft+i-ileft, pright-1);
		return cur;
	}

	// question 112 path sum
	template<typename T>
	bool hasPathSum(TreeNode<T>* root, T target) {
		if (root == nullptr) return false;
		if (root->left == nullptr && root->right == nullptr && root->val == target) return true;
		return hasPathSum(root->left, target-root->val) || hasPathSum(root->right, target-root->val);
	}

	// question 113 path sum II
	template<typename T>
	std::vector< std::vector<T> > pathSum(TreeNode<T>* root, T targetSum) {
		std::vector< std::vector<T> > res;
		std::vector<T> path;

	}

	template<typename T>
	void pathSumHelper(TreeNode<T>* root, T& targetSum, std::vector<T>& path, std::vector< std::vector<T> >& res) {
		if (!root) return;
		path.push_back(root->val);
		if (!root->left && !root->right && root->val == targetSum) {
			res.push_back(path);
		}
		pathSumHelper(root->left, targetSum-root->val, path, res);
		pathSumHelper(root->right, targetSum-root->val, path, res);
		path.pop_back();
	}

	template<typename T>
	TreeNode<T>* sortedListToBST(ListNode<T>* head) {
		// find root node in list
		if (!head) return nullptr;
		if (!head->next) return new TreeNode<T>(head->val);
		ListNode<T> *slow=head, *fast=head, *last=slow;
		while(fast->next && fast->next->next) {
			last = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode<T>* head_right = slow->next;
		last->next = nullptr;
		ListNode<T>* head_left = head;

		TreeNode<T>* cur_node = new TreeNode<T>(slow->val);
		if (head_left != slow) cur_node->left = sortedListToBST(head_left);
		cur_node->right = sortedListToBST(head_right);
		return cur_node;
	}

	template<typename T>
	ListNode<T>* initList(std::vector<T> nums) {
		ListNode<T>* head = new ListNode<T>(nums[0]);
		ListNode<T>* pnode = head;
		for (int i=1; i<nums.size(); ++i) {
			ListNode<T>* ptmp = new ListNode<T>(nums[i]);
			pnode->next = ptmp;
			pnode=ptmp;
		}
		return head;
	}

	template<typename T>
	void ShowList(ListNode<T>* head) {
		while (head != nullptr) {
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}

	template<typename T>
	ListNode<T>* ReverseList(ListNode<T>* head) {
		ListNode<T> *prev=nullptr, *cur=head, *tmp;
		while (cur) {
			tmp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = tmp;
		}
		return prev;
	}

	template<typename T>
	T findMedium(ListNode<T>* head) {
		ListNode<T> *slow=head, *fast=head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow->val;
	}

};

int main() {
	Solution s;
	// std::vector<int> nums = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
	/*
	TreeNode<int>* root = new TreeNode<int>(1);
	root->left = new TreeNode<int>(2);
	root->right = new TreeNode<int>(3);
	root->left->left = new TreeNode<int>(4);
	root->right->right = new TreeNode<int>(5);

	std::vector< std::vector<int> > result = s.zigzagLevelOrder(root);
	cout << "nums of layer : " << result.size() << endl;
	s.showVec(result);
	*/

	TreeNode<int>* root = new TreeNode<int>(5);
	root->left = new TreeNode<int>(4);
	root->right = new TreeNode<int>(8);
	root->left->left = new TreeNode<int>(11);
	root->right->left = new TreeNode<int>(13);
	root->right->right = new TreeNode<int>(9);

	// s.PreOrder(root);
	// cout << endl;
	// s.InOrder(root);
	// cout << endl;
	// s.PostOrder(root);
	// cout << endl;

	// std::vector<int> pre_order 	= {5, 4, 11, 8, 13, 9};
	std::vector<int> in_order  	= {9, 3, 15, 20 ,7}; // {11, 4, 5, 13, 8, 9};
	std::vector<int> post_order = {9, 15, 7, 20, 3}; // {11, 4, 13, 9, 8, 5};
	s.showVec(in_order);
	// s.showVec(pre_order);
	// TreeNode<int>* result = s.buildTree(pre_order, in_order);
	// s.PreOrder(result);
	// cout << endl;

	cout << "build post tree" << endl;
	TreeNode<int>* post_result = s.buildTreePost(post_order, in_order);
	s.InOrder(post_result);
	cout << endl;


	cout << "list to bst" << endl;
	std::vector<int> nums = {-10, -3, 1, 5, 9}; // {1,2,3,4,5,6,7,8,9,10,11};
	ListNode<int>* head = s.initList(nums);
	// s.ShowList(head);
	TreeNode<int>* bst = s.sortedListToBST(head);
	s.PreOrder(bst);
	cout << endl;
	// head = s.ReverseList(head);
	// s.ShowList(head);
	// cout << "medium: " << s.findMedium(head) << endl;


}
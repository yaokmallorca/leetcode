#include <iostream>
#include <vector>

using namespace std;

// the node of tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class btree{
public:
	TreeNode *root;

public:
	btree(){root = nullptr;}
	~btree(){destory_free();}

	void insert(int key) {
		if (root != nullptr) {
			insert(key, root);
		} else {
			root = new TreeNode(key);
		}
	}

	void insert(int key, TreeNode* leaf) {
		if (key < leaf->val) {
			if (leaf->left != nullptr) {
				insert(key, leaf->left);
			} else {
				leaf->left = new TreeNode(key);
			}
		} else if (key >= leaf->val) {
			if (leaf->right != nullptr) {
				insert(key, leaf->right);
			} else {
				leaf->right = new TreeNode(key);
			}
		}
	}

	TreeNode* search(int key, TreeNode* leaf) {
		if (leaf != nullptr) {
			if (key == leaf->val) {
				return leaf;
			}
			if (key < leaf->val) {
				return search(key, leaf->left);
			} else {
				return search(key, leaf->right);
			}
		} else {
			return nullptr;
		}
	}

	void delete_leaf(int key, TreeNode*& leaf) {
		if (leaf != nullptr) {
			if (key == leaf->val) {
				destory_free(leaf);
				return;
			}
			if (key < leaf->val) {
				return delete_leaf(key, leaf->left);
			} else {
				return delete_leaf(key, leaf->right);
			}
		} else {
			return;
		}
	}

	TreeNode* search(int key) {
		search(key, root);
	}

	void destory_free(TreeNode* node) {
		if (node != nullptr) {
			destory_free(node->left);
			destory_free(node->right);
			delete node;
			node = nullptr;
		}
	}

	void destory_free() {
		destory_free(root);
	}

	void inorder_print() {
		inorder_print(root);
		cout << endl;
	}

	void inorder_print(TreeNode* leaf) {
		if (leaf != nullptr) {
			inorder_print(leaf->left);
			cout << leaf->val << ", " ;
			inorder_print(leaf->right);
		}
	}

	void postorder_print() {
		postorder_print(root);
		cout << endl;
	}

	void postorder_print(TreeNode* leaf) {
		if (leaf != nullptr) {
			postorder_print(leaf->left);
			postorder_print(leaf->right);
			cout << leaf->val << ", ";
		}
	}

	void preorder_print() {
		preorder_print(root);
		cout << endl;
	}

	void preorder_print(TreeNode* leaf) {
		if (leaf != nullptr) {
			cout << leaf->val << ", ";
			preorder_print(leaf->left);
			preorder_print(leaf->right);
		}
	}

};


class Solution {
public:
	TreeNode* root;
public:

	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p || !q) return false;
		bool isSameLeft = isSameTree(p->left, q->left);
		bool isSameRight = isSameTree(p->right, q->right);
		return isSameLeft && isSameRight && p->val == q->val;
	}

	int rangeSumBST(TreeNode* root, int low, int high) {
		if (!root) return 0;
		if (root->val < low) return rangeSumBST(root->right, low, high);
		if (root->val > high) return rangeSumBST(root->left, low, high);
		return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
	}

	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1) return t2;
		if (!t2) return t1;
		TreeNode* t = new TreeNode(t1->val + t2->val);
		t->left = mergeTrees(t1->left, t2->left);
		t->right = mergeTrees(t1->right, t2->right);
		return t;
	}

	std::vector< std::vector<int> > levelOrderBottom(TreeNode* root) {
		std::vector< std::vector<int> > res;
		levelorder(root, 0, res);
		return vector< vector<int> > (res.rbegin(), res.rend());
	}

	void levelorder(TreeNode* node, int level, std::vector< std::vector<int> >& res) {
		if (!node) return;
		if (res.size() == level) res.push_back({});
		res[level].push_back(node->val);
		if (node->left) levelorder(node->left, level+1, res);
		if (node->right) levelorder(node->right, level+1, res);
	}

	/*
	bool isValidBST(TreeNode* root) {
		TreeNode *pre = NULL;
		return inorder(root, pre);
	}

	bool val_inorder(TreeNode* node, TreeNode* pre) {
		if (!node) return true;
		bool res = val_inorder(node->left, pre);
		if (!res) return false;
		if (pre) {if (node->val < pre->val) return false;} 
		pre = node;
		res = val_inorder(node->right, pre);
		return res;
	}
	*/
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}
	bool isValidBST(TreeNode* root, long mn, long mx) {
		if (!root) return true;
		if (root->val <= mn || root->val >= mx) return false;
		return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
	}

	bool isSymmetric(TreeNode* root) {
		if (!root) return false;
		return isSymmetric(root->left, root->right);
	}

	bool isSymmetric(TreeNode* left, TreeNode* right) {
		if (!left && !right) return true;
		if (!left && right || left && !right || left->val != right->val) return false;
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}

	TreeNode* sortedArrayToBST(std::vector< std::vector<int> >& nums) {
		if (nums.size() == 0) return NULL;
		int mid = int(nums.size() / 2);
		TreeNode* node = new TreeNode(nums[mid]);
		std::vector<int> left_vec(nums.begin(), nums.begin()+mid);
		std::vector<int> right_vec(nums.begin()+mid+1, nums.end());
		node->left = sortedArrayToBST(left_vec);
		node->right = sortedArrayToBST(right_vec);
		return node;
	}

	int maxPathSum(TreeNode* root) {
		int ret = INT_MIN;
		realMaxPathSu(root, ret);
		return ret;
	}

	int realMaxPathSum(TreeNode* node, int& res) {
		if (node == nullptr) return 0;
		int left = max(0, realMaxPathSum(node->left));
		int right = max(0, realMaxPathSum(node->right));
		res = max(res, left + right + node->val);
		return max(left, right) + node->val;
	}
};

int main() {

	btree* tree = new btree();
	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);

	cout << "preorder: " << endl;
	tree->preorder_print();
	cout << "inorder: " << endl;
	tree->inorder_print();
	cout << "postorder: " << endl;
	tree->postorder_print();

	tree->delete_leaf(8, tree->root);
	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();
	delete tree;
}
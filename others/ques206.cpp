#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* head;

	void initList(std::vector<int> nums) {
		int len = nums.size();
		head = new ListNode(nums[0]);
		ListNode* head_tmp = head;
		ListNode* prev = head, *node; 

		for (int i = 1; i < len; ++i) {
			/* code */
			node = new ListNode(nums[i]);
			prev->next = node;
			prev = node;
		}
	}

	void showList() {
		ListNode* pnode = head;
		while(pnode->next != nullptr && pnode != nullptr) {
			cout << pnode->val << " ";
			pnode = pnode->next;
		}
		cout << endl;
	}
};


int main(int argc, char const *argv[])
{
	std::vector<int> nums = {1,2,3,4,5};
	Solution s;
	s.initList(nums);
	s.showList();

	return 0;
}
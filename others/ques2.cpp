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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(-1), *head = dummy;
		int carry = 0;
		while(l1 != nullptr || l2 != nullptr) {
			int val1 = l1 != nullptr ? l1->val : 0;
			int val2 = l2 != nullptr ? l2->val : 0;
			int sum = val1 + val2 + carry;
			int t = sum % 10;
			carry = sum / 10;
			ListNode* node = new ListNode(t);
			head->next = node;
			head = head->next;
			l1 = (l1 != nullptr) ? l1->next : nullptr;
			l2 = (l2 != nullptr) ? l2->next : nullptr;
		}
		if (carry > 0){
			ListNode* node = new ListNode(carry);
			head->next = node;
			head = head->next;
		}
		return dummy->next;
	}


	ListNode* initList(std::vector<int> nums) {
		ListNode* dummy = new ListNode(-1);
		ListNode* head = dummy;
		for (auto num : nums) {
			ListNode* node = new ListNode(num);
			head->next = node;
			head = head->next;
		}
		return dummy->next;
	}

	void showList(ListNode* head) {
		while (head != nullptr) {
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}

	ListNode* reverseList(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		ListNode *prev = dummy, *cur = head;
		while (cur != nullptr) {
			ListNode* t = cur->next;
			cur->next = prev;
			prev = cur;
			cur = t;
		}
		head->next = nullptr;
		return prev;
	}

	ListNode* reverseListII(ListNode* head) {
		if (head->next == nullptr) return head;
		ListNode* last = reverseListII(head->next);
		head->next->next = head;
		head->next = nullptr;
		return last;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> num1 = {1,2,3,4,5};
	std::vector<int> num2 = {1};
	Solution s;

	ListNode* l1 = s.initList(num1);
	s.showList(l1);
	ListNode* t = s.reverseListII(l1);
	s.showList(t);

	ListNode* l2 = s.initList(num2);
	s.showList(l2);

	ListNode* l3 = s.addTwoNumbers(t, l2);
	s.showList(l3);

	return 0;
}
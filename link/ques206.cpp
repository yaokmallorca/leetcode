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
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) return nullptr;
		ListNode* newHead = nullptr;
		while (head) {
			ListNode* t = head->next;
			head->next = newHead;
			newHead = head;
			head = t;
		}
		return newHead;
	}

	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* newHead = reverseList(head->next);
		cout << head->val << ", " << head->next->val << endl;
		head->next->next = head;
		head->next = nullptr;
		return newHead
	}
	
};

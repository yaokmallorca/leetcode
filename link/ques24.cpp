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
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) return nullptr;
		ListNode *dummy = new ListNode(-1), *pre = dummy;
		dummy->next = head;

		while (pre->next != nullptr && pre->next->next != nullptr) {
			ListNode* pt = pre->next->next;
			pre->next->next = pt->next;
			t->next = pre->next;
			pre->next = t;
			pre = t->next;
		}
		return dummy->next;
	}
	
};


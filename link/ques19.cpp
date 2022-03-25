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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head->next == nullptr) return nullptr;
		ListNode* pre = head, cur = head;
		for (int i = 0; i < n; ++i) {
			/* code */
			cur = cur->next;
		}
		if(cur->next == nullptr) return head->next;
		while(cur->next != nullptr) {
			pre = pre->next;
			cur = cur->next;
		}
		pre->next = pre->next->next;
		return head;
	}
};
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

	// O(nlogn) mergesort 
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *slow, *fast, *pre;
		ListNode *res;
		while(fast != nullptr && fast->next != nullptr) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = nullptr;
		return merge(sortList(head), sortList(slow));
	}
	

	ListNode* merge(ListNode* l1, ListNode* l2) {
		cout << "l1: " << l1->val << ", l2: " << l2->val << endl;
		ListNode* dummy = new ListNode(-1), *cur=dummy;
		while(l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next
			} else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		while(l1 != nullptr) {cur->next = l1;}
		while(l2 != nullptr) {cur->next = l2;}
		return dummy->next;
	}
};
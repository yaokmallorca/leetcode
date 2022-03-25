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
	ListNode* insertSortList(ListNode* head) {
		if (head == nullptr) return nullptr;
		ListNode* dummy = ListNode(-1), *res = dummy;
		ListNode* node1 = head, node2 = head->next;

		while (node1 != nullptr) {
			while (node2 != nullptr) {
				if (node1->val < node2->val) {
					ListNode* tmp = new ListNode(node1->val);
					res->next = tmp;
				} else {
					ListNode* tmp = new ListNode(node2->val);
					res->next = tmp;
				}
				res = res->next;
				node2 = node2->next;
			}
			node1 = node1->next;
		}
		return dummy->next;
	}
};


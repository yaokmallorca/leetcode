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
	bool hasCircle(ListNode* head) {
		if (head == nullptr) return false;
		ListNode *fast = head, *slow = head;

		while(fast && fast->next) {
			if (slow == fast) return true;
			slow = slow->next;
			fast = fast->next->next;
		}


		return false;
	}
	
};
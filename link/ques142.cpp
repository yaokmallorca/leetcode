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
	ListNode* detectCycle(ListNode* head) {
		ListNode *fast=head, *slow=head;

		while(!fast&& !fast->next) {
			if (fast == slow) break;
			slow = slow->next;
			fast = fast->next->next;
		}

		if (fast == nullptr || fast->next == nullptr) return nullptr;
		fast = head;
		while (fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
	
};


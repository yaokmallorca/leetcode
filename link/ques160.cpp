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
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (headA == nullptr || headB == nullptr) return nullptr;
		ListNode* node = nullptr;
		int lenA = getListLength(headA);
		int lenB = getListLength(headB);
		if (lenA < lenB) {
			for (int i = 0; i < lenB - lenA; ++i) { headB = headB->next;}
		}
		if (lenA > lenB) {
			for (int i = 0; i < lenA - lenB; ++i) { headA = headA->next;}
		}

		while(headA != nullptr && headB != nullptr) {
			if (headA == headB) {
				node = headA;
				break;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return node;
	}

	int getListLength(ListNode* head) {
		int res = 0; 
		while (head != nullptr) {
			++res;
			head = head->next;
		}
		return res;
	}
	
};
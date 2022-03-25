#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

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
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) return true;
		ListNode *slow = head, *fast = head;
		stack<int> st{{head->val}};
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			st.push(slow->val);
		}
		if (!fast->next) st.pop();
		while (slow->next) {
			slow = slow->next;
			int tmp = st.top(); st.pop();
			if (tmp != slow->val) return false;
		}
		return true;
	}
	

};
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* head;

public:
	~Solution() {
		while(head != NULL) {
			delete head;
			head = head->next;
		}
		head = NULL;
	}

	ListNode* initNode(std::vector<int> nums) {
		ListNode* node = new ListNode(nums[0]);
		ListNode* head = node;
		for (int i=1; i<nums.size(); i++) {
			ListNode* tmp = new ListNode(nums[i]);
			node->next = tmp;
			node = tmp;
		}
		return head;
	}


	void showList(ListNode* head) {
		while(head != NULL) {
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}

	void deleteNode(ListNode* node){
		ListNode* prev = head;
		ListNode* tmp = head;
		while(head != NULL) {
			if (head->val == node->val) {
				prev->next = head->next;
				delete head;
				break;
			}
			prev = head;
			head = head->next;
		}
		head = tmp;
	}

	void deleteNthNode(int n) {
		int i=0;
		ListNode* tmp = head;
		ListNode* prev = head;
		while(head != NULL) {
			if (i == n) {
				prev->next = head->next;
				delete head;
				break;
			}
			++i;
			prev = head;
			head = head->next;
		}
		head = tmp;
	}


	ListNode* removeNthFromEnd(int n) {
		ListNode* prev = head;
		ListNode* pcur = head;
		for(int i=0; i<n; i++) {
			pcur = pcur->next;
		}
		if(pcur == NULL) return head;
		while(pcur->next != NULL) {
			prev = prev->next;
			pcur = pcur->next;
		}
		ListNode* pnode = prev->next;
		prev->next = prev->next->next;
		delete pnode;
		return head;
	} 

	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* pcur = head;
		ListNode* prev = head;
		while(pcur != NULL) {
			ListNode* pnode = pcur->next;
			pcur->next = prev;
			prev = pcur;
			pcur = pnode;
		}
		head->next = NULL;
		return prev;
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			} else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = (l1 != NULL) ? l1 : l2;
		return dummy->next;
	}

	bool isPalindromeList(ListNode* head) {
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

	bool hasCycle(ListNode* head) {
		ListNode *slow = head, *fast = head;
		while (fast!=NULL && fast->next!=NULL) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) return true;
		}
		return false;
	}
};

int main() {
	std::vector<int> nums = {1,2,3,4,5,6,7,8};
	Solution s;
	s.head = s.initNode(nums);
	s.showList(s.head);

	ListNode* node = new ListNode(4);
	s.deleteNode(node);
	s.showList(s.head);
	delete node;

	s.deleteNthNode(3);
	s.showList(s.head);

	cout << "remove nth from end" << endl;
	s.removeNthFromEnd(3);
	s.showList(s.head);

	std::vector<int> nums1 = {1, 4, 6};
	std::vector<int> nums2 = {2, 3, 4};
	ListNode* l1 = s.initNode(nums1);
	ListNode* l2 = s.initNode(nums2);

	ListNode* merge_ret = s.mergeTwoLists(l1, l2);
	s.showList(merge_ret);

	cout << "PalindromeList" << endl;
	std::vector<int> palin_vec = {1,2,3,4,4,3,2,1};
	ListNode* palin_list = s.initNode(palin_vec);
	bool is_palin_ret = s.isPalindromeList(palin_list);
	cout << "palin list result: " << is_palin_ret << endl;

}
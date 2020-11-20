#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return reverseList(l2);
		if (l2 == nullptr)
			return reverseList(l1);

		l1 = reverseList(l1);
		l2 = reverseList(l2);
		int carry = 0, left = 0;
		ListNode* sum = nullptr;
		ListNode* head = nullptr;
		ListNode* prev = nullptr;
		while (l1 != nullptr && l2 != nullptr) {
			sum = new ListNode();
			if (head == nullptr)
				head = sum;
			int real_val = l1->val + l2->val;
			left = real_val % 10;
			sum->val = left + carry;
			carry = real_val / 10;
			if (prev != nullptr) 
				prev->next = sum;
			prev = sum;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1 == nullptr && l2 == nullptr){
			return head;
		}
		if (l1 == nullptr && l2 != nullptr){
			ListNode* tmp = l2;
			while (carry != 0){
				sum = new ListNode();
				if(l2 == nullptr)
					l2 = new ListNode();
				int real_val = l2->val + carry;
				left = real_val % 10;
				sum->val = left;
				carry = real_val / 10;
				if (prev != nullptr) 
					prev->next = sum;
				prev = sum;
				l2 = l2->next;
			}
			return head;
		} else {
			ListNode* tmp = l1;
			while (carry != 0){
				sum = new ListNode();
				if(l1 == nullptr)
					l1 = new ListNode();
				int real_val = l1->val + carry;
				left = real_val % 10;
				sum->val = left;
				carry = real_val / 10;
				if (prev != nullptr) 
					prev->next = sum;
				prev = sum;
				l1 = l1->next;
			}
			return head;
		}
	}

	ListNode* reverseList(ListNode* l1) {
		if (l1 == nullptr) return nullptr;
		ListNode* curr = l1->next;
		ListNode* prev = l1;
		ListNode* next = nullptr;
		while(curr != nullptr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		l1->next = nullptr;
		l1 = prev;
	}

	void scanList(ListNode* head) {
		while (head != nullptr) {
			cout << head->val << " ";
			head = head->next;
		}
		cout<<endl;
	}


	/*
	ListNode* addTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		int target = l1->val + l2->val;
		ListNode* res = new ListNode(target % 10);
		cout << "res: " << res->val << endl;
		res->next = addTwoLists(l1->next, l2->next);
		if (res->next != nullptr)
			cout << "res->next: " << res->next->val << endl;
		if (target >= 10){
			res->next = addTwoLists(res->next, new ListNode(1));
			cout << "carry: " << res->next->val << endl;
		}
		cout << "#################" << endl;
		delete l1, l2;
		return res;
	}
	*/


	ListNode* addTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		int real_val = l1->val + l2->val;
		int left = real_val % 10;
		int carry = real_val / 10;
		ListNode* res = new ListNode(left);
		res->next = addTwoLists(l1->next, l2->next);
		cout << "input: " << l1->val << ", " << l2->val << endl;
		cout << "res: " << res->val << endl;
		if (res->next != nullptr)
			cout << "res->next: " << res->next->val << endl;
		cout << "#################### " << endl;
		if(carry > 0) {
			res->next = addTwoLists(res->next, new ListNode(carry));
			cout << "carry: " << res->next->val << endl;
			cout << "<<<<<<<<<<<<<<<<<<<<<" << endl;
		}
		delete l1, l2;
		return res;
	}

};

int main() {
	// int a[7] = {1,3,4,6,9,7,2};
	// int b[4] = {9,7,8,4};
	int a[7] = {2,4,3};
	int b[4] = {5,6,4};
	int len_a = 3;
	int len_b = 3;
	Solution s;

	ListNode* l1=new ListNode(a[0]);
	ListNode* l2=new ListNode(b[0]);
	ListNode* l1_head = l1;
	ListNode* l2_head = l2;
	ListNode* tmp;;
	for(int i=1; i<len_a; i++) {
		tmp = new ListNode(a[i]);
		l1->next = tmp;
		l1 = tmp;
	}

	tmp = nullptr;
	for(int i=1; i<len_b; i++) {
		tmp = new ListNode(b[i]);
		l2->next = tmp;
		l2 = tmp;
	}
	s.scanList(l1_head);
	s.scanList(l2_head);
	cout << "##############" << endl;

	/* 
	ListNode* result = nullptr;
	result = s.addTwoNumbers(l2_head, l1_head);
	cout << "finish add" << endl;
	s.scanList(result);
	cout << "##############" << endl;
	*/

	ListNode* res = nullptr;
	res = s.addTwoLists(l1_head, l2_head);
	s.scanList(res);
	return 0;
}
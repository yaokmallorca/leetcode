#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <utility>
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
	ListNode* InitList(vector<int> input) {
		ListNode* head = new ListNode(input[0]);
		ListNode* ptr = head;
		int N = input.size();
		for(int i=1; i<N; i++) {
			ListNode* node = new ListNode(input[i]);
			ptr->next = node;
			ptr = node;
		}
		return head;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head->next) return nullptr;
		ListNode *prev = head, *curr = head;
		for (int i=0; i<n; i++) {
			curr = curr->next;
		}
		if (!curr) return head->next;
		while (curr->next != nullptr) {
			prev = prev->next;
			curr = curr->next;
		}
		prev->next = prev->next->next;
		return head;
	}

	void showList(ListNode* head) {
		if (head == nullptr) return;
		ListNode* node = head;
		while(node != nullptr) {
			cout << node->val << ", ";
			node = node->next;
		}
		cout << endl;
	}
};

int main() {
	// int c[6] = {1, 0, -1, 0, -2, 2};
	int c[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	vector<int> arr1;
	for(int i=0; i<12; i++) {
		arr1.push_back(c[i]);
	}

	Solution s;
	ListNode* head = s.InitList(arr1);
	s.showList(head);
	ListNode* newlist = s.removeNthFromEnd(head, 4);
	s.showList(newlist);
	return 0;
}
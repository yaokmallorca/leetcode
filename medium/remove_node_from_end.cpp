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
	ListNode* head;

public:
	void initList(vector<int> input) {
		ListNode *pnode, *list;
		head = new ListNode(input[0]);
		list = head;
		int N = input.size();
		for(int i=1; i<N; i++) {
			pnode = new ListNode(input[i]);
			list->next = pnode;
			list = pnode;
		}
	}

	void addNode(ListNode* head, int val) {
		ListNode* pnode = new ListNode(val);
		head->next = pnode;
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

	int lengthList(ListNode* head) {
		int len = 0;
		ListNode* list = head;
		while (list != nullptr) {
			len += 1;
			list = list->next;
		}
		return len;
	}

	ListNode* removeNthFromEnd1(ListNode* head, int n) {
		int len = lengthList(head);
		if (n>=len) {return nullptr;}
		int index = len - n;
		ListNode *list = head, *prev;
		int node_cnt = 0;
		while(list != nullptr) {
			if (node_cnt == index) {
				ListNode *tmp = list->next;
				list = list->next;
				prev->next = tmp;
				node_cnt += 1;
			} else {
				prev = list;
				list = list->next;
				node_cnt += 1;
			}
		}
		return head;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head->next) return nullptr;
		ListNode *prev = head, *curr = head;
		for (int i = 0; i<n; i++) {
			curr = curr->next;
		}
		if (!curr) return head->next;
		while( curr->next) {
			curr = curr->next;
			prev = prev->next;
		}
		prev->next = prev->next->next;
		return head;
	}
};

int main() {
	// int c[6] = {1, 0, -1, 0, -2, 2};
	int c[2] = {1, 2};
	vector<int> arr1;
	for(int i=0; i<2; i++) {
		arr1.push_back(c[i]);
	}

	Solution s;
	s.initList(arr1);
	s.showList(s.head);
	s.head = s.removeNthFromEnd(s.head, 1);
	cout<<"result: "<< endl;
	s.showList(s.head);

	return 0;
}
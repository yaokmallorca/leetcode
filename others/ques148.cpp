#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <map>
#include <utility> // pair

using namespace std;

template<typename T>
struct ListNode
{
	T val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(T x) : val(x), next(nullptr) {}
	ListNode(T x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	template <typename T>
	ListNode<T>* sortList(ListNode<T>* head) {


		return head;
	}
	

	template<typename T>
	ListNode<T>* initList(std::vector<T> nums) {
		ListNode<T> *head = new ListNode<T>(nums[0]), *node=nullptr;
		node = head;
		for (int i=1; i<nums.size(); ++i) {
			ListNode<T>* tmp = new ListNode<T>(nums[i]);
			node->next = tmp;
			node = tmp;
		}
		return head;
	}

	template<typename T>
	ListNode<T>* ReverseList(ListNode<T>* head) {
		ListNode<T>* cur = head;
		ListNode<T> *prev = nullptr, *next = nullptr;
		while (cur) {
			ListNode<T>* tmp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = tmp;
		}
		return prev;
	}

	template<typename T>
	void showList(ListNode<T>* head) {
		ListNode<T>* pnode = head;
		while (pnode != nullptr) {
			cout << pnode->val << " ";
			pnode = pnode->next;
		}
		cout << endl;
	}

	template<typename T>
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}


	template<typename T>
	void MergeSort(std::vector<T>& arr, int low, int high) {
		if (low >= high) return;
		int mid = low + (high - low) / 2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}

	template<typename T>
	void merge(std::vector<T>& arr, int low, int mid, int high) {
		int i = low, j = mid+1, k = 0;
		std::vector<T> temp(high - low + 1, 0);
		while (i <= mid && j <= high) {
			if (arr[i] <= arr[j])
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		while (i<=mid) 
			temp[k++] = arr[i++];
		while (j<=high) 
			temp[k++] = arr[j++];
		for (i=low, k=0; i<=high; i++, k++) {
			arr[i] = temp[k];
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> vecs = {-1,5,3,4,0};

	s.MergeSort(vecs, 0, vecs.size());
	s.showVec(vecs);


	ListNode<int>* head = s.initList(vecs);
	s.showList(head);

	head = s.ReverseList(head);
	s.showList(head);

	return 0;
}
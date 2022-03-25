#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	int findKthLargest(std::vector<int>& nums, int k) {
		if (nums.empty()) return 0;
		mergeSort(nums, 0, nums.size()-1);
		showVec(nums);
		int pos = nums.size() - k;
		return nums[pos];
	}

	void mergeSort(std::vector<int>& nums, int l, int r) {
		if (l < r) {
			cout << l << ", " << r << endl;
			int mid = l + (r - l) / 2;
			mergeSort(nums, l, mid);
			mergeSort(nums, mid+1, r);
			merge(nums, l, mid, r);
		}
	}

	void merge(std::vector<int>& nums, int l, int mid, int r) {
		std::vector<int> tmp(r - l + 1, 0);
		int l_ind = l, r_ind = mid+1, pos = 0;

		while(l_ind <= mid && r_ind <= r) {
			if (nums[l_ind] < nums[r_ind]) {
				tmp[pos++] = nums[l_ind++];
			} else {
				tmp[pos++] = nums[r_ind++];
			}
		}

		while (l_ind <= mid) tmp[pos++] = nums[l_ind++];
		while (r_ind <= r)   tmp[pos++] = nums[r_ind++];

		for (int i = 0; i < pos; ++i) {
			nums[l+i] = tmp[i];
		}
	}
	

	void showVec(std::vector<int>& nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {3,2,3,1,2,4,5,5,6};
	Solution s;

	cout << s.findKthLargest(nums, 4) << endl;
	return 0;
}
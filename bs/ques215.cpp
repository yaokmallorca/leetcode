#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	/*
	int findKthLargest(std::vector<int>& nums, int k) {
		int left = 0, right = nums.size() - 1;
		while (true) {
			showVec(nums);
			int pos = partition(nums, left, right);
			if (pos == k - 1) return nums[pos];
			if (pos > k - 1) right = pos - 1;
			else left = pos + 1;
		}
	} 

	int partition(std::vector<int> nums, int left, int right) {
		int pivot = nums[left], l = left + 1, r = right;
		while (l <= r) {
			if (nums[l] < pivot && nums[r] > pivot) {
				swap(nums[l++], nums[r--]);
			}
			if (nums[l] >= pivot) ++l;
			if (nums[r] <= pivot) --r;
		}
		swap(nums[left], nums[r]);
		return r;
	}
	*/

	int findKthLargest(vector<int>& nums, int k) {
		int left = 0, right = nums.size() - 1;
		while (true) {
			int pos = partition(nums, left, right);
			showVec(nums);
			// cout << "pos: " << pos << endl;
			if (pos == k - 1) return nums[pos];
			if (pos > k - 1) right = pos - 1;
			else left = pos + 1;
			cout << "<<<<<<<<<<<<<<<<<<<<" << endl;
		}
	}

	int partition(std::vector<int>& nums, int left, int right) {
		int val = nums[right];
		for (int i=left; i<right; ++i) {
			if (nums[i] > val) swap(nums[left++], nums[i]);
		}
		cout << "partition: ";
		showVec(nums);
		swap(nums[right], nums[left]);
		return left;
	}


	/*
	int partition(vector<int>& nums, int left, int right) {
		int pivot = nums[left], l = left + 1, r = right;
		while (l <= r) {
			if (nums[l] < pivot && nums[r] > pivot) {
				swap(nums[l++], nums[r--]);
			}
			if (nums[l] >= pivot) ++l;
			if (nums[r] <= pivot) --r;
		}
		swap(nums[left], nums[r]);
		return r;
	}
	*/

	void showVec(std::vector<int> nums) {
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
	s.showVec(nums);
	int res = s.findKthLargest(nums, 4);
	cout << "res: " << res << endl; 
	return 0;
}
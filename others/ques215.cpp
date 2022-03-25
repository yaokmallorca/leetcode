#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int findKthLargest(std::vector<int> nums, int k) {

		return 0;
	}
	
	template<typename T>
	int partition(std::vector<T>& nums, int left, int right) {
		T pivot = nums[left];
		while (left < right) {
			while (left < right && nums[right] >= pivot) --right;
			// nums[left] = nums[right];
			swap(nums[left], nums[right]);
			while (left < right && nums[left] <= pivot) ++left;
			// nums[right] = nums[left];
			swap(nums[left], nums[right]);
		}
		// nums[left] = pivot;
		return left;
	}

	template<typename T>
	void quickSort(std::vector<T>&nums, int left, int right) {
		if (left < right) {
			int pivot = partition(nums, left, right);
			quickSort(nums, left, pivot - 1);
			quickSort(nums, pivot + 1, right);
		}
	}

	template<typename T>
	void mergerSort(std::vector<T>& nums, int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2; 
			mergerSort(nums, left, mid);
			mergerSort(nums, mid+1, right);
			merge(nums, left, mid, right);
		}

	}

	template<typename T>
	void merge(std::vector<T>& nums, int left, int mid, int right) {
		std::vector<T> tmp(right - left + 1, 0);
		int l_ind = left, r_ind = mid + 1, pos = 0;
		while (l_ind <= mid && r_ind <= right) {
			if (nums[l_ind] < nums[r_ind]) {
				tmp[pos++] = nums[l_ind++];
			} else {
				tmp[pos++] = nums[r_ind++];
			}
		}
		while (l_ind <= mid) tmp[pos++] = nums[l_ind++];
		while (r_ind <= right) tmp[pos++] = nums[r_ind++];
		for (int i = 0; i < tmp.size(); ++i) {
			/* code */
			nums[left + i] = tmp[i];
		}
	}

	template<typename T>
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {1,5,7,4,23,76,123,11};
	Solution s;

	s.showVec(nums);
	s.quickSort(nums, 0, nums.size()-1);
	// s.mergerSort(nums, 0, nums.size() - 1);
	s.showVec(nums);
	// cout << s.findKthLargest(nums, 3) << endl;
	return 0;
}

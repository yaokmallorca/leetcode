#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

class Solution
{
public:
	void mergeSort(std::vector<int>& nums, int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			mergeSort(nums, left, mid);
			mergeSort(nums, mid+1, right);
			merge(nums, left, mid, right);
		}
	}

	void merge(std::vector<int>& nums, int left, int mid, int right) {
		int l_ind = left, r_ind = mid+1, pos = 0;
		std::vector<int> tmp(right - left + 1, 0);
		while (l_ind <= mid && r_ind <= right) {
			if (nums[l_ind] < nums[r_ind]) {
				tmp[pos++] = nums[l_ind++];
			} else {
				tmp[pos++] = nums[r_ind++];
			}
		}
		while (l_ind <= mid) tmp[pos++] = nums[l_ind++];
		while (r_ind <= right) tmp[pos++] = nums[r_ind++];
		for (int i = 0; i < pos; ++i) {
			/* code */
			nums[left+i] = tmp[i];
		}
	}


	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	int maxSubArray1(std::vector<int>& nums) {
		int res = INT_MIN, cur_sum = 0;
		for(auto num : nums) {
			cur_sum += max(num, cur_sum + num);
			res = max(res, cur_sum);
		}
		return res;
	}

	int maxSubArray(std::vector<int> nums) {
		if (nums.size()<=1) return nums.empty() ? 0 : nums[0];
		int sum=0, max_sum = INT_MIN;
		for(int i=0; i<nums.size(); ++i) {
			sum = max(nums[i], nums[i]+sum);
			max_sum = max(max_sum, sum);
		}
		return max_sum;
	}
	
};

int main(int argc, char const *argv[])
{
	// std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	// s.mergeSort(nums, 0, nums.size()-1);
	// s.showVec(nums);
	cout << s.maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) << endl;
	cout << s.maxSubArray({1}) << endl;
	cout << s.maxSubArray({5,4,-1,7,8}) << endl;
	return 0;
}
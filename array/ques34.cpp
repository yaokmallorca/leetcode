#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return {-1,-1};
		if (nums.size() == 1) {
			if (nums[0] == target) return {0,0};
			else return {-1,-1};
		}
		int pos = binarySearch(nums, target);
		cout << "pos: " << pos << endl;
		if (pos == -1) return {-1, -1};
		int left_range = pos, right_range = pos;
		while(left_range > 1 && nums[left_range] == nums[left_range-1]) --left_range; 
		while(right_range < nums.size()-2 && nums[right_range] == nums[right_range+1]) ++right_range;
		return {left_range, right_range};
	}

	int binarySearch(vector<int>& nums, int target) {
		
		int left = 0, right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		return -1;

		/*
		int left = 0, right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		return -1;
		*/
	}

	/*
	vector<int> searchRange(vector<int>& nums, int target) {
		int idx = search(nums, 0, nums.size() - 1, target);
		cout << "idx: " << idx << endl;
		if (idx == -1) return {-1, -1};
		int left = idx, right = idx;
		while (left > 0 && nums[left - 1] == nums[idx]) --left;
		while (right < nums.size() - 1 && nums[right + 1] == nums[idx]) ++right;
		return {left, right};
	}
	*/

	template<typename T> 
	void showVec(std::vector<T>& nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {1, 3};
	Solution s;
	std::vector<int> res = s.searchRange(nums, 1);
	s.showVec(res);
	return 0;
}
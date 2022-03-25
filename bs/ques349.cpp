#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
	std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::unordered_set<int> res;
		std::vector<int> nums_short;
		std::vector<int> nums_long;
		if (nums1.size() < nums2.size()) {
			nums_short = nums1;
			nums_long = nums2;
		} else {
			nums_short = nums2;
			nums_long = nums1;
		}
		sort(nums_long.begin(), nums_long.end());
		// sort(nums_short.begin(), nums_short.end());

		for (auto num_s : nums_short) {
			/* code */
			if (res.count(num_s)) continue;
			if (binarySearch(nums_long, num_s)) {
				res.insert(num_s);
			}
		}
		return std::vector<int>(res.begin(), res.end());
	}

	bool binarySearch(std::vector<int> nums, int target) {
		int left = 0, right = nums.size();
		while(left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return true;
			}
			if (nums[mid] < target) {
				left = mid+1;
			} else {
				right = mid;
			}
		}
		return false;

	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums1 = {4,9,5};
	std::vector<int> nums2 = {9,4,9,8,4};

	Solution s;
	std::vector<int> res = s.intersection(nums1, nums2);
	s.showVec(res);

	return 0;
}
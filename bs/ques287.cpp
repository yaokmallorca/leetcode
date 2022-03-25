#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
	int findDuplicate(vector<int>& nums) {
		int left = 1, right = nums.size();
		int mid = 0;
		while (left < right) {
			int mid = left + (right - left) / 2;
			int cnt = 0;
			for (int num : nums) {
				cnt += (num <= mid);
			}
			if (cnt <= mid) left = mid + 1;
			else right = mid;
		}
		return right;
	}

	void sort(std::vector<int>& nums) {
		int n = nums.size()-1;
		for (int i = 1; i < n-1; ++i) {
			/* code */
			while (nums[i] != i && nums[i] <= n && nums[i] != nums[nums[i]]) {
				// cout << i << ", " << nums[i] << ", " << nums[nums[i]] << endl;
				swap(nums[i], nums[nums[i]]);
			}
		}
	}

	int findDuplicateSort(std::vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			/* code */
			while (nums[i]-1 != i && nums[i]-1 < n && nums[i] != nums[nums[i]-1]) {
				swap(nums[i], nums[nums[i]-1]);
			}
		}
		for (int i = 0; i < n; ++i) {
			/* code */
			if (nums[i] != i)
				return nums[i];
		}
		return -1;
	}


	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout <<endl;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {4,5,1,6,2,3}; // {3,1,3,4,2,8,6,5,7};
	Solution s;
	s.showVec(nums);
	cout << s.findDuplicateSort(nums) << endl;
	s.showVec(nums);
	return 0;
}
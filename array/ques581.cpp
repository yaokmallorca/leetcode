#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


class Solution
{
public:
	int findUnsortedSubarray1(std::vector<int>& nums) {
		std::vector<int> newNums(nums.begin(), nums.end());
		sort(newNums.begin(), newNums.end());
		int n = nums.size(), left = 0, right = n-1;
		for (int i = 0; i < n; ++i) {
			/* code */
			if (nums[i] != newNums[i]){
				left = max(i, left);
				break;
			}
		}

		for (int i = n-1; i > 0; --i) {
			/* code */
			if (nums[i] != newNums[i]) {
				right = min(i, right);
				break;
			}
		}
		cout << left << ", " << right << endl;
		return right - left + 1;
	}
	
	int findUnsortedSubarray(std::vector<int>& nums) {
		int n = nums.size(), start = -1, end = -2;
		int mn = nums[n-1], mx = nums[0];

		for (int i = 0; i < n; ++i) {
			/* code */
			mx = max(mx, nums[i]);
			mn = min(mn, nums[n - 1 - i]);
			if (mx > nums[i]) end = i;
			if (mn < nums[n - 1 - i]) start = n - 1 - i;
		}
		return end - start + 1;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {2,6,4,8,10,9,15};
	Solution s;
	cout << s.findUnsortedSubarray(nums) << endl;

	return 0;
}
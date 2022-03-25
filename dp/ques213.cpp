#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int rob(std::vector<int> nums) {
		if (nums.size() <= 1) return nums.empty() ? 0 : *max_element(nums.begin(), nums.end());
		return max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));
	}

	int rob(std::vector<int> nums, int left, int right) {
		if (right - left <= 1) return nums[left];
		std::vector<int> dp(right, 0);
		dp[left] = nums[left]; dp[left + 1] = max(nums[left], nums[left + 1]);
		// dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
		for (int i = left + 2; i < right; ++i) {
			/* code */
			dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
		}
		return dp.back();
	}
};


int main(int argc, char const *argv[])
{
	std::vector<int> nums = {1,2,3,1};
	Solution s;
	cout << s.rob(nums) << endl;
	return 0;
}
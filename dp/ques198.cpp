#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int rob(std::vector<int>& nums) {
		// dp[i] = max(nums[i] + dp[i-2], dp[i-1])
		if (nums.size() <= 1) return nums.empty() ? 0 : *max_element(nums.begin(), nums.end());
		int n = nums.size();
		std::vector<int> dp(n, 0);
		dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
		for (int i=2; i<n; ++i) {
			dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
		}
		

		return dp.back();
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}


	int rob(std::vector<int>& nums) {
		if (nums.size() <= 2) return nums.empty() ? 0 : *max_element(nums.begin(), nums.end());
		int n = nums.size();
		std::vector<int> dp(n, 0);
		dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);

		for (int i = 2; i < n; ++i) {
			/* code */
			dp[i] += max(nums[i] + dp[i-2], dp[i-1]);
		}
		return dp.back();
	}

	int robII(std::vector<int>& nums) {
		if (nums.size() <= 2) return nums.empty() ? 0 : *max_element(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		return max(robHelper(nums, left + 1, right), robHelper(nums, left, right - 1));
	}

	int robHelper(std::vector<int>& nums, int left, int right) {
		std::vector<int> dp(right-left, 0);
		dp[0] = nums[left]; dp[1] = max(nums[left], nums[left+1]);
		for (int i = left+2; i < right; ++i) {
			/* code */
			dp[i] += max(nums[i] + dp[i-2], dp[i-1]);
		}
		return dp.back();
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {3,1};
	// cout << *max_element(nums.begin(), nums.end()) << endl;
	Solution s;
	cout << s.rob(nums) << endl;

	return 0;
}
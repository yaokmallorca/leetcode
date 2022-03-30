#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	// dp[i][j] is related to dp[i-1][j]
	// 198. house robber 
	/* 
		dp[i] = max(dp[i-1], 			// do not rob the ith house
					dp[i-2]+nums[i]) 	// rob the ith house


	*/
	int rob(std::vector<int>& nums) {
		if (nums.size() <= 1) return nums.empty() ? 0 : *max_element(nums.begin(), nums.end());
		int n = nums.size();
		std::vector< int> dp(n, 0);
		dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < n; ++i) {
			/* code */
			dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
		}
		return dp.back();
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	// 213
	int robII(std::vector<int>& nums) {
		if (nums.size() <= 1) return nums.empty() ? 0 : *max_element(nums.begin(), nums.end());
		int n = nums.size();
		std::vector<int> nums1 = std::vector<int>(nums.begin(), nums.end()-1);
		std::vector<int> nums2 = std::vector<int>(nums.begin()+1, nums.end());
		int max1 = rob(nums1);
		int max2 = rob(nums2);
		return max(max1, max2);
	}

	// 123, 309
	int maxProfit(std::vector<int>& prices) {
		int buy = INT_MAX, res = 0;
		for (auto p : prices) {
			int t = min(p, buy);
			res = max(t, t-p)
		}


	}

};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {1,2,3,1};
	Solution s;
	cout << s.robII(nums) << endl;
	return 0;
}
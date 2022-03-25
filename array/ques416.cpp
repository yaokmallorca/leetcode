#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
	bool canPartition1(std::vector<int>& nums) {
		if (nums.size() <= 1) return false;
		int n = nums.size();
		// sort(nums.begin(), nums.end());
		std::vector<int> sums(nums.size(), 0);
		sums[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			/* code */
			sums[i] = sums[i-1] + nums[i] ;
		}
		showVec(sums);
		for (int i = 0; i < nums.size(); ++i) {
			cout << sums[i] << ", " << sums[n-1] << ", " << sums[n-1] - sums[i] << endl;
			if (sums[i] == (sums[n-1] - sums[i])) 
				return true;
		}
		return false;
	}

	bool canPartition(std::vector<int>& nums) {
		int sum_arr = accumulate(nums.begin(), nums.end(), 0);
		if (sum_arr & 1) return false;
		int target = sum_arr >> 1, n = nums.size();
		std::vector< std::vector<bool> > dp(n, std::vector<bool>(target+1, false));

		if (nums[0] <= target)
			dp[0][nums[0]] = true;

		for (int i = 1; i < n; ++i) {
			/* code */
			for (int j = 0; j <= target; ++j) {
				dp[i][j] = dp[i-1][j];
				if (nums[i] == j) { 
					dp[i][j] = true; continue;
				} 
				if (nums[i] < j) {
					// 不选择 nums[i] 或 选择 nums[i]
					dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
					// dp[i][j] = dp[i-1][j-nums[i]];
				}
				// cout << "i: " << i << ", j: " << j << endl;
			}
		}
		showVec(dp);
		return dp.back().back();

	}

	bool canPartition12(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
		if (sum & 1) return false;
		vector<bool> dp(target + 1, false);
		dp[0] = true;
		for (int num : nums) {
			for (int i = target; i >= num; --i) {
				dp[i] = dp[i] || dp[i - num];
			}
		}
		return dp[target];
	}


	template<typename T>
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	template<typename T>
	void showVec(std::vector< std::vector<T> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums1 = {1, 5, 11, 5};
	std::vector<int> nums2 = {1, 2, 3,  5};
	std::vector<int> nums3 = {1, 2, 5};  // {2, 2, 1,  1};
	Solution s;

	cout << s.canPartition(nums1) << endl;
	// cout << "<<<<<<<<<<<<<<<<<<<" << endl;
	// cout << s.canPartition(nums2) << endl;
	cout << "<<<<<<<<<<<<<<<<<<<" << endl;
	cout << s.canPartition(nums3) << endl;
	return 0;
}
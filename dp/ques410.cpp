#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
	int splitArrayDP(std::vector<int> nums, int m) {
		// dp[i][j]: the min of max of sum of i subarrays, splitted from 0 to j
		// dp[1][j]: the sum from 0  to j
		// dp[i][j]: min( max_{j subarray}(dp[i-1][k], sum(j) - sum[k]) ), 0<k<=j

		int n = nums.size();
		std::vector<long> sub_sum(n+1, 0); 
		std::vector< std::vector<long> > dp(m+1, std::vector<long>(n+1, LONG_MAX));
		dp[0][0] = 0;
		for(int i=1; i<=n; ++i) {
			sub_sum[i] = nums[i-1] + sub_sum[i-1];
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = i-1; k < j; ++k) {
					long tmp = max(dp[i-1][k], sub_sum[j]-sub_sum[k]);
					dp[i][j] = min(dp[i][j], tmp);
				}
			}
		}
		return dp.back().back();
	}


	template<typename T>
	void showVec(std::vector<T> nums) {
		for (T num : nums) {
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
	std::vector<int> nums = {7,2,5,10,8};
	Solution s;
	cout << s.splitArrayDP(nums, 2) << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << s.splitArray(nums, 2) << endl;

	return 0;
}
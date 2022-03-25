#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int deleteAndEarn(std::vector<int>& nums) {
		if (nums.empty()) return 0;
		int r = *max_element(nums.begin(), nums.end());
		std::vector<int> scores(r+1, 0);
		for (auto num : nums) {
			scores[num] += num;
		}

		showVec(scores);
		// dp[i] = max(dp[i-2] + nums[i], dp[i-1])
		return rob(scores);
	}

	int rob(std::vector<int> nums) {
		int n = nums.size();
		std::vector<int> dp(n, 0);
		dp[0] = 0; dp[1]=nums[1];
		for(int i=2; i<n; ++i) {
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
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {2,2,3,3,3,4};
	Solution s;
	cout << s.deleteAndEarn(nums) << endl;
	return 0;
}
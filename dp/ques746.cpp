#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int minCostClimbingStairs(std::vector<int>& cost) {
		int n = cost.size();
		std::vector<int> dp(n+1, 0);
		for (int i=2; i<=n; ++i) {
			dp[i] = min(dp[i-2] + cost[i-2], dp[i-1]+cost[i-1]);
			cout << dp[i] << ", " << dp[i-1] << ", " << dp[i-2] << endl;
		}
		showVec(dp);
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
	std::vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
	Solution s;
	cout << s.minCostClimbingStairs(cost) << endl;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	// 70
	int climbStairs(int n) {
		if (n<=1) {return 1;}
		std::vector<int> dp(n);
		dp[0] = 1; dp[1] = 2;
		for (int i=2; i<n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp.back();
	}

	// 198
	int rob(vector<int>& nums) {
		if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
		// cout << nums.size() << endl;
		std::vector<int> dp(nums.size());
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		// cout << "11111" << endl;
		for (int i=2; i<nums.size(); i++) {
			// dp.push_back(max(nums[i]+dp[i-2], dp[i-1]));
			dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
		}
		// cout << "dp size: " << dp.size() << endl;
		return dp.back();
	}

	// 746
	int minCostClimbingStairs(std::vector<int>& cost) {
		int n = cost.size();
		std::vector<int> dp;
		dp.push_back(cost[0]);
		dp.push_back(min(cost[0], cost[1]));
		for (int i=2; i<n; i++) {
			dp.push_back(min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]));
		}
		return dp.back();
	}

	// 790
	// dp[n] = dp[n-1] + dp[n-2] + 2*(dp[n-3] + ... + dp[0])
	int minTiling(int N) {
		int M = 1e+7;
		std::vector<long> dp(N+1);
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for (int i=3; i<=N; i++){
			dp[i] = (dp[i-1] * 2 + dp[i-3]) % M;
		}
		return dp[N];
	}

	// 801 ??????????????
	int minSwap(std::vector<int>& A, std::vector<int> B) {
		int res = 0;
		std::vector< std::vector<int> > dp(A.size(), vector<int>(2, 0));
		dp[0][0] = 0;
		dp[0][1] = 1;
		for (int i=1; i<A.size(); i++) {
			if (A[i-1] < A[i] && B[i-1] < B[i]) {
				if (A[i-1] < B[i] && B[i-1] < A[i]) { // change or don't change, get the optimal
					dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
					dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1;
				} else {
					dp[i][0] = dp[i-1][0]; // do not change, the previous position cannot change
					dp[i][1] = dp[i-1][1] + 1; // change, the previous position must change
				} 
			} else {
				dp[i][0] = dp[i-1][1]; // dont change, the previous must be changed
				dp[i][1] = dp[i-1][0] + 1; // change. the previous cannot change
			}
		} 
		return min(dp[A.size()-1][0], dp[A.size()-1][1]);
	}

	// 139
	bool wordBreak(string s, std::vector<string> wordDict) {
		unorder_set<string> wordSet(wordDict.begin(), wordDict.end());
		std::vector<bool> dp(s.size() + 1);
		dp[0] = true;
		for (int i=0; i<dp.size(); i++) {
			for (int j=0; j<i; j++) {
				if (dp[j] && wordSet.count(s.substr(j, j-i))) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp.back();
	}

	// 818
	int racecar(int target) {
		
		
	}

	// 72

	// 312

	// 664

	// 673

	// 546

	// 322

	// 494

};

int main() {
	Solution s;
	cout << "climbStairs: " << s.climbStairs(3) << endl;

	std::vector<int> houses = {2,7,9,3,1};
	cout << "rob house: " << s.rob(houses) << endl;

	std::vector<int> stair_cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1}; 
	cout << "min stairs cost: " << s.minCostClimbingStairs(stair_cost) << endl;

	std::vector<int> A = {1,3,5,4};
	std::vector<int> B = {1,2,3,7};
	cout << "min swap times: " << s.minSwap(A, B) << endl;

}
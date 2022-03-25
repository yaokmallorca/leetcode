#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int climbStars(int n) {
		std::vector<int> dp(n+1, 0);
		dp[1] = 1; dp[2] = 2;
		for (int i=3; i<=n; ++i) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp.back();
	}

	int climbStars1(int n) {
		if (n <= 1) return 1;
		std::vector<int> dp(n, 0);
		dp[0] = 1; dp[1] = 2;
		for (int i = 2; i < n; ++i) {
			/* code */
			dp[i] += dp[i-1] + dp[i-2];
		}
		return dp[n-1];
	}
};

int main(int argc, char const *argv[]) {
	int m = 3;
	Solution s;
	int res = s.climbStars(m);
	cout << "res: " << res << endl;
	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int numTrees1(int n) {
		if (n <= 1) return 1;
		std::vector<int> dp(n+1, 0);
		dp[0] = 1; dp[1] = 1;
		for (int i=2; i<=n; ++i) {
			for (int j=0; j<i; ++j) {
				dp[i] += dp[i-j-1] * dp[j];
			}
		}

		showVec(dp);
		return dp[n];
	}


	int numTrees(int n) {
		if (n <= 1) return 1;
		int res = 0;
		for (int i=0; i<n; ++i) {
			res += numTrees(i) * numTrees(n-i-1);
		}
		return res;
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) 
			cout << num << " ";
		cout << endl;
	}
};


int main(int argc, char const *argv[])
{
	/* code */
	int n = 4;
	Solution s;
	int res1 = s.numTrees1(n);
	cout << "res1: " << res1 << endl;

	int res = s.numTrees(n);
	cout << "res: " << res << endl;
	return 0;
}

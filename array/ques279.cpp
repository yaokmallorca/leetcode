#include <stdlib.h>
#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
	int numSquares1(int n) {
		int res = n, num = 2;
		while (num * num <= n) {
			int a = n / (num * num), b = n % (num * num);
			res = min(res, a + numSquares(b));
			cout << "res: " << res << ", num: " << num << ", a: " << a << ", b: " << b << endl; 
			++num;
		}
		return res;
	}

	int numSquares_dp(int n) {
		std::vector<int> dp(n+1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i <= n; ++i) {
			for (int j = 1; i + j*j <= n; ++j) {
				dp[i + j*j] = min(dp[i + j*j], dp[i]+1);
			}
		}
		showVec(dp);
		return dp.back();
	}
	
	// dp[n] = min(dp[n-k]) + 1 k is square numbre
	int numSquares(int n) {
		std::vector<int> square_nums;
		for (int i = 1; i < sqrt(n); ++i) { square_nums.push_back(i*i); }
		showVec(square_nums);
		std::vector<int> dp(n+1, INT_MAX);
		dp[0] = 0;

		for (int i = 1; i < n+1; ++i) {
			/* code */
			for (auto sn : square_nums) {
				// if (i < sn) break;
				dp[i] = min(dp[i], dp[i - sn] + 1);
			}
		}
		showVec(dp);
		return dp.back();
	}

	void showVec(std::vector<int> nums) {
		for(auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a = 13;
	cout << s.numSquares(a) << endl;

	return 0;
}

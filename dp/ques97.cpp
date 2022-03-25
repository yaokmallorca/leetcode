#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	/*
	dp[i][j] whether s3[0 : i+j] can be obtained usng s1[0 : i] and s2[0 : j].
	dp[i][j] = dp[i-1][j] && s1[i] == s3[i+j-1] or dp[i][j-1] && s2[j] == s3[i+j-1]
	*/
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) return false;
		int n1 = s1.size(), n2 = s2.size();
		std::vector< std::vector<bool> > dp(n1+1, std::vector<bool>(n2+1, false));
		dp[0][0] = true;
		for (int i = 1; i <= n1; ++i) {
			dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
		}
		for (int i = 1; i <= n2; ++i) {
			dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
		}

		for (int i = 1; i <= n1; ++i) {
			for (int j = 1; j <= n2; ++j) {
				dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i-1+j]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
			}
		}
		return dp[n1][n2];
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
	Solution s;
	string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"; // "aadbbcbcac";
	cout << s.isInterleave(s1, s2, s3) << endl;

	return 0;
}
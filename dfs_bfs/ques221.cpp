#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int maximalSquare(std::vector< std::vector<char> >& matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int m = matrix.size(), n = matrix[0].size(), res = 0;
		std::vector< std::vector<int> > dp(m, std::vector<int>(n, 0));

		for (int i = 0; i < m; ++i) {
			/* code */
			for (int j = 0; j < n; ++j) {
				/* code */
				if (i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
				else if (matrix[i][j] == '1') {
					dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
				}
				res = max(res, dp[i][j]);
			}
		}

		showVec(dp);
		return res * res;
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	void showVec(std::vector< std::vector<int> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}

};

int main(int argc, char const *argv[])
{
	std::vector< std::vector<char> > square = {{'1', '0', '1', '0', '0'},
											   {'1', '0', '1', '1', '1'},
											   {'1', '1', '1', '1', '1'},
											   {'1', '0', '0', '1', '0'}};
	Solution solution;
	cout << solution.maximalSquare(square) << endl;

	return 0;
}
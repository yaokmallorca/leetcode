#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int uniquePath(int m, int n) {
		int res = 0;
		std::vector< std::vector<int> > dp(m, std::vector<int>(n, 0));
		for (int i = 0; i < m; ++i) { dp[i][0] = 1; }
		for (int i = 0; i < n; ++i) { dp[0][i] = 1; }
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				/* code */
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
	}

	int uniquePathWithObstacle(std::vector< std::vector<int> > grids) {
		int rows = grids.size();
		int cols = grids[0].size();
		std::vector< std::vector<int> > dp(rows, std::vector<int>(cols, 0));
		for (int i = 0; i < rows; ++i) { dp[i][0] = 1; }
		for (int i = 0; i < cols; ++i) { dp[0][i] = 1; }
		for (int r = 1; r < rows; ++r) {
			for (int c = 1; c < cols; ++c) {
				if (grids[r][c] == 1) {
					continue;
				} else {
					dp[r][c] = dp[r-1][c] + dp[r][c-1];
				}
			}
		}
		return dp[rows-1][cols-1];

		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
		dp[0][1] = 1;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (obstacleGrid[i - 1][j - 1] != 0) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m][n];
	}
};

int main(int argc, char const *argv[]) {
	/* code */
	int m=3, n=7, res=0;
	Solution s;
	res = s.uniquePath(m, n);
	cout << "res: " << res << endl;

	std::vector< std::vector<int> > grids = {{0,0,0},{0,1,0},{0,0,0}};
	int res2 = 0;
	res2 = s.uniquePathWithObstacle(grids);
	cout << "res: " << res2 << endl;
	return 0;
}
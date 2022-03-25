#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int minPathSum(std::vector< std::vector<int> > grids) {
		int m = grids.size(), n = grids[0].size();
		std::vector< std::vector<int> > dp(m, std::vector<int>(n, 0));
		dp[0][0] = grids[0][0];
		for (int i = 1; i < m; ++i) { dp[i][0] = dp[i-1][0] + grids[i][0]; }
		for (int i = 1; i < n; ++i) { dp[0][i] = dp[0][i-1] + grids[0][i]; }
		showVec(dp);
		for (int i=1; i<m; ++i) {
			for (int j=1; j<n; ++j) {
				dp[i][j] = grids[i][j] + min(dp[i-1][j], dp[i][j-1]);
			}
		}
		showVec(dp);
		return dp[m-1][n-1];
	}

	void showVec(std::vector< std::vector<int> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
		cout << endl;
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

};

int main(int argc, char const *argv[]) {
	std::vector< std::vector<int> > grids = {{1,3,1},{1,5,1},{4,2,1}};
	Solution s;
	s.showVec(grids);
	int res = s.minPathSum1(grids);
	cout << "res: " << res << endl;
	return 0;
}
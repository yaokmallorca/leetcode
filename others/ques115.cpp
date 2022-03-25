#include <iostream>
#include <string>
#include <cstring> // strcmp
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <map>
#include <climits>
#include <iterator> // iterator
#include <algorithm> // reverse
#include <utility> // pair

using namespace std;

// remove last letter in string, out.pop_back()

class Solution
{
public:
	int numDistinct(string s, string t) {
		int m = s.size(), n = t.size();
		std::vector< std::vector<unsigned int> > dp(n+1, std::vector<unsigned int>(m+1, 0));
		for (int j=0; j<=m; ++j) dp[0][j] = 1;
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=m; ++j) {
				dp[i][j] = dp[i][j-1] + (t[i-1]==s[j-1] ? dp[i-1][j-1] : 0); 
			}
		}
		return dp[n][m];
	}

	std::vector<string> findAndReplacePattern(std::vector<string>& words, string pattern) {
		
		
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

int main() {
	Solution solution;

	string s = "rabbbit";
	string t = "rabbit";
	int result = solution.numDistinct(s, t);
	cout << "ques 115 result: " << result << endl;

	return 0;
}
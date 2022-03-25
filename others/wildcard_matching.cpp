#include <iostream>
#include <string>
#include <cstring> // strcmp
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <map>
#include <utility> // pair

using namespace std;

class Solution
{
public:
	void showVec(std::vector<bool> vec) {
		for (auto v : vec) {
			cout << v << " ";
		}
		cout << endl;
	}

	void showVec(std::vector< std::vector<bool> > vecs) {
		for (std::vector< std::vector<bool> >::iterator iter = vecs.begin(); iter != vecs.end(); ++iter) {
			showVec(*iter);
		}
	}


	// * Matches any sequence of characters (including the empty sequence).
	// ? Matches a single letter.
	bool isMatch(string s, string p) {
		cout << "s: " << s.c_str() << endl;
		cout << "p: " << p.c_str() << endl;

		int m  = s.size(), n = p.size();
		std::vector< std::vector<bool> > dp(m+1, std::vector<bool>(n+1, false));
		cout << "array: "<< endl;
		showVec(dp);
		dp[0][0] = true;
		for (int i=1; i<=n; ++i) { 
			if (p[i-1] == '*') dp[0][i] = dp[0][i-1];
		}
		cout << "array: "<< endl;
		showVec(dp);
		for (int i=1; i<=m; ++i) {
			for (int j=1; j<=n; ++j) {
				if (p[j-1] == '*') {
					dp[i][j] = dp[i-1][j] || dp[i][j-1];
				} else {
					dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
				}
			}
		}
		cout << "array: " << endl;
		showVec(dp);
		return dp[m][n];
	}

	// '.' matches a single letter
	// '*' matches any numbers of preceding letters
	bool isRegularMatch(string s, string p) {
		int m = s.size(), n = p.size();
		std::vector< std::vector<bool> > dp(m+1, std::vector<bool> (n+1, false));
		dp[0][0] = true;
		for (int i=0; i<=m; ++i) {
			for (int j=1; j<=n; ++j) {
				if (j>1 && p[j-1] == '.') {
					dp[i][j] = dp[i][j-2] || (i>0 && (s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
				} else {
					dp[i][j] = i>0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
				}
			}
		}
		return dp[m][n];
	}

};

int main() {
	Solution solution;

	string s = "abcde", p = "*a*b";
	bool isMatched = solution.isMatch(s, p);
	cout << "p and s are: " << isMatched << endl;


	string s1 = "mississippi", p1 = "mis*is*p*.";
	bool isExMatched = solution.isRegularMatch(s1, p1);
	cout << "p1 and s1 are: " << isExMatched << endl;


	return 0;
}
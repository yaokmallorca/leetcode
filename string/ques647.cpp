#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int countSubString(string s){
		int res = 0;
		std::vector<string> strs;

		for (int i = 0; i < s.size(); ++i) {
			/* code */
			// countSubStringHelper(strs, res, i, i, s);
			// countSubStringHelper(strs, res, i, i+1, s);
			helper(strs, res, i, i, s);
			helper(strs, res, i, i+1, s);
		}
		showVec(strs);
		return res;
	}

	void countSubStringHelper(std::vector<string>& strs, int& res, int left, int right, string s) {
		if (right >= s.size()) return;
		while (left >= 0 && right < s.size()) {
			if (s[left] == s[right]) {
				++res; --left; ++right;
				string t = s.substr(left, right - left);
				strs.push_back(t);
			}
		}
	}

	void showVec(std::vector<string> strs) {
		for (auto s : strs) {
			cout << s << endl;
		}
	}

	void helper(std::vector<string>& strs, int& res, int left, int right, string s) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			string t = s.substr(left, right - left + 1);
			if (t.size() > 0)
				strs.push_back(t);
			--left; ++right; ++res;
		}
	}

	int countSubStringDP(string s) {
		if (s.empty()) return 0;
		int n = s.size(), res = 0;
		std::vector<string> strs;
		std::vector< std::vector<bool> > dp(n, std::vector<bool>(n, false));

		// for (int i = 0; i < n; ++i) {
		for (int i = n - 1; i >= 0; --i) {
			/* code */
			for (int j = i; j < n; ++j) {
				dp[i][j] = (s[i] == s[j]) && (j-i<2 || dp[i+1][j-1]);
				if (dp[i][j]) {
					strs.push_back(s.substr(i, j-i+1));
					++res;
				}
			}
		}
		showVec(strs);
		return res;
	}

};


int main(int argc, char const *argv[])
{
	string str = "aaabbacc";
	Solution s;
	cout << s.countSubString(str) << endl;

	cout << "dynamic programming" << endl;
	cout << s.countSubStringDP(str) << endl;

	return 0;
}
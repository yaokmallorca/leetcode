#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	string longestPalindrome(string s) {
		if (s.size() < 2) return s;
		int n = s.size();
		int maxlen = 0, start = 0;
		for (int i = 1; i < n-1; ++i) {
			// odd length string
			searchLongestPalindrome(s, i, i, start, maxlen);
			// even length string
			searchLongestPalindrome(s, i, i+1, start, maxlen);
		}
		cout << start << ", " << maxlen << endl;
		return s.substr(start, maxlen);
	}

	void searchLongestPalindrome(string s, int left, int right, int& start, int& maxlen) {
		while (left >=0 && right<s.size() && s[left] == s[right]) {
			--left; ++right;
		}
		int str_len = right - left - 1;
		cout << "str_len: " << str_len << endl;
		cout << "maxlen: " << maxlen << endl;
		if (maxlen < right - left - 1) {
		// if (maxlen<str_len) {
			cout << "search: " << left << ", " << right << endl;
			maxlen = right - left - 1;
			start = left+1;
		}
		cout << "<<<<<<<<<<<<<<<<<<<<<" << endl;
	}


	string longestPalindromeDP(string s) {
		if (s.size() <= 1) return s; 
		int n = s.size();
		std::vector< std::vector<int> > dp(n, std::vector<int>(n, 0));
		// dp[n][n] = 0;
		int left = 0, maxlen = 1;
		// dp[i][j] = (s[i-1] == s[j+1]) && dp[i+1][j-1]
		for (int i = 0; i < n; ++i) {
			/* code */
			dp[i][i] = 1;
			for(int j=0; j<i; ++j) {
				dp[j][i] = (s[i] == s[j]) && (dp[j+1][i-1] || i-j>=2); 
				if (i-j+1 > maxlen && dp[j][i]) {
					left = j;
					maxlen = i - j + 1;
				} 
			}
		}
		return s.substr(left, maxlen);
	}

	string longestPalindromeDP1(string s) {
		if (s.empty()) return "";
		int n = s.size(), dp[n][n] = {0}, left = 0, len = 1;
		for (int i = 0; i < n; ++i) {
			dp[i][i] = 1;
			for (int j = 0; j < i; ++j) {
				dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
				if (dp[j][i] && len < i - j + 1) {
					len = i - j + 1;
					left = j;
				}
			}
		}
		return s.substr(left, len);
	}
};

int main(int argc, char const *argv[]) {
	string str_in = "babad";
	Solution s;
	string str_out = s.longestPalindromeDP(str_in);
	cout << "result: " << str_out << endl;

	return 0;
}
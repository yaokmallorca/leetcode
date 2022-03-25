#include <stdlib.h>
#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	// 
	string longestPalindrome(string str) {
		int n = str.size();
		int max_len = INT_MIN;
		string res = "";
		for (int i = 1; i < n-1; ++i) {
			/* code */
			longestPalindrome(str, i, i, max_len, res);
			longestPalindrome(str, i, i+1, max_len, res);
		}
		return res;
	}

	// dft method
	void longestPalindrome(string str, int left, int right, int& max_len, string& res) {
		if (right >= str.size() || left < 0) return;
		while (left >=0 && right < str.size() && str[left-1] == str[right+1]) {
			--left; ++right;
		}
		int t = right - left + 1;
		if (t > max_len) {
			max_len = t;
			res = str.substr(left, t);
		}
	}

	// dp
	/*
	dp[i][j]: i to j is palindrome
	dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]

	*/
	string longestPalindromeDP(string str) {
		string res = "";
		int max_len = INT_MIN, n = str.size(), left = 0;
		std::vector< std::vector<int> > dp(n, std::vector<int>(n, 0));
		for(int i=0; i<n; ++i) dp[i][i] = 1;

		for (int i = 1; i < n; ++i) {
			/* code */
			for (int j=0; j < i; ++j) {
				dp[j][i] = (str[i] == str[j] && (i - j < 2 || dp[j + 1][i - 1]));
				if (dp[j][i] && max_len < i - j + 1) {
					max_len = i - j + 1;
					left = j;
				}
			}
		}
		res = str.substr(left, max_len);
		return res;
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
	string str = "cbbd"; // "babad";
	Solution s;
	cout << s.longestPalindromeDP(str) << endl;
	return 0;
}
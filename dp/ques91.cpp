#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0') return 0;
		std::vector<int> dp(s.size()+1, 0);
		dp[0] = 1;
		for(int i=1; i<dp.size(); ++i) {
			cout << s[i] << endl;
			// if (s[i] != '0') dp[i] = dp[i-1];
			dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
			if (i>=2 && s.substr(i-2, 2)<="26" && s.substr(i-2, 2)>="10"){
				cout << s.substr(i-2, 2) << endl; 
				dp[i] += dp[i-2];
			}
			cout << "<<<<<<<<<<<<<" << endl;
		}
		showVec(dp);
		return dp[s.size()];
	}
	
	/*
		if (s.empty() || s[0] == '0') return 0;
		std::vector<int> dp(s.size()+1, 0);
		dp[0] = 1;
		for (int i = 1; i < dp.size(); ++i) {
			cout << s[i] << endl;
			if (s[i] != '0') dp[i] += dp[i-1];
			if (i >= 2 && s.substr(i-2, 2) <= "26" && s.substr(i-2, 2) >= "10")
				dp[i] += dp[i-2];
		}
		showVec(dp);
		return dp[s.size()-1];
	*/

	void showVec(std::vector<int> nums) {
		for (auto num : nums) 
			cout << num << " ";
		cout << endl;
	}
};

int main(int argc, char const *argv[]) {
	string str = "2101";
	Solution s;
	int res = s.numDecodings(str);
	cout << "results: " << res << endl;
	return 0;
}
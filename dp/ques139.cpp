#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	bool wordBreak(string s, std::vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		std::vector<int> mems(s.size(), 0);
		// return wordBreakDFS(s, wordSet, 0);
		return wordBreakDFS(s, wordSet, 0, mems);
	}

	bool wordBreakDFS(string s, unordered_set<string>& wordSet, int start) {
		if (start >= s.size()) return true;
		for (int i=start+1; i<=s.size(); ++i) {
			string sub_str = s.substr(start, i-start);
			if (wordSet.count(sub_str) && wordBreakDFS(s, wordSet, i)) {
				return true;
			} 
		}
		return false;
	}

	bool wordBreakDFS1(string s, unordered_set<string> wordSet, int start, std::vector<int>& mems) {
		if (start >= s.size()) return true;
		if (mems[start] == 1) return true;

		for(int i=start+1; i<=s.size(); ++i) {
			if (mems[i] == 1) return true;
			string sub_str = s.substr(start, i-start);
			if (wordSet.count(sub_str) && wordBreakDFS(s, wordSet, i, mems)) {
				mems[i] = 1;
				return true;
			}
		}
		mems[start] = 0;
		return false;
	}

	bool wordBreakDFS(string s, unordered_set<string> wordSet, int start, std::vector<int>& mems) {
		if (start >= s.size()) return true;
		if (mems[start] == 1) return true;
		for (auto word : wordSet) {
			int word_len = word.size();
			string sub_str = s.substr(start, word_len);
			if (wordSet.count(sub_str) && wordBreakDFS(s, wordSet, start+word_len, mems)) {
				mems[start] = 1;
				return true;
			}
		}
		mems[start] = 0;
		return false;
	}

	bool wordBreakDP(string s, std::vector<string> wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		std::vector<bool> dp(s.size()+1, false); 
		dp[0] = true;

		// dp[j] : whether can be break before j
		// dp[i] = dp[i-1] && wordSet.cout(s.substr(j, i-j))
		for (int i=1; i<dp.size(); ++i) {
			/* code */
			for (int j=0; j<i; ++j) {
				if (dp[j] && wordSet.count(s.substr(j, i-j))) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp.back();
	}
};

int main(int argc, char const *argv[])
{
	string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	std::vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	
	// string str = "applepenapple";
	// std::vector<string> wordDict = {"apple", "pen"};

	// string str = "catsandog";
	// std::vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"}; 
	Solution s;
	bool res = s.wordBreakDP(str, wordDict);
	cout << "res: " << res << endl;
	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> umap;
		int n = s.size(), left = 0, max_len = INT_MIN;
		for (int i=0; i<n; ++i) {
			++umap[s[i]];
			if (umap[s[i]] > 1) {
				max_len = max(i - left, max_len);
				left = i;
			}
		}
		return max_len;
	}
	
};

int main(int argc, char const *argv[])
{
	string str = "pwwkew"; // "abcabcbb";
	Solution s;
	cout << s.lengthOfLongestSubstring(str) << endl;
	return 0;
}
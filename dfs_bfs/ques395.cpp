#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int longestSubstring(string s, int k) {
		int max_len = INT_MIN;
		int left = 0, right = 0, n = s.size();
		unordered_map<char, int> umap;

		while (right < n) {
			if (right - left < k) {
				++umap[s[right++]];
			} else {
				// cout << s.substr(left, right-left) << endl;
				int tmp = INT_MAX;
				for (auto i : umap) {
					// cout << i.first << ", " << i.second << endl;
					tmp = min(tmp, i.second);
				}
				// cout << "min_num: " << tmp << endl;
				if (tmp >= k) {
					cout << s.substr(left, right-left) << endl;
					max_len = max(max_len, right - left);
					if (umap.count(left) > 0)
						--umap[s[left++]];
				}
				++umap[s[right++]];
				// cout << "<<<<<<<<<<<<<<<<<<<<<<" << endl;
			}
		}
		return max_len;
	}
};

int main(int argc, char const *argv[])
{
	string str1 = "ababbc";
	int k1 = 2;
	Solution s;
	cout << s.longestSubstring(str1, k1) << endl;

	string str2 = "aaabb";
	int k2 = 3;
	cout << s.longestSubstring(str2, k2) << endl;
	return 0;
}
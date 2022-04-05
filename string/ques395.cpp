#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:

	// sliding window
	int longestSubstring_sliding(string s, int k) {
		int N = 26, ret = 0;
		for (int i = 1; i <= N; ++i) {
			/* code */
			ret = max(ret, helper(s, i, k));
		}
		return ret;
	}
	
	int helper(string& s, int m, int k) {
		int ret = 0;
		int r = 0, cnt = 0; // the number of character, whose freq is >= k
		unordered_map<char, int> umap;
		for (int l=0; l<s.size(); ++l) {
			while (r < s.size() && umap.size() <= m) {
				umap[s[r]]++;
				if (umap[s[r]] == k) cnt++;
				if (cnt == m && umap.size() == m) {
					ret = max(r-l+1, ret);
				}
				++r;
			}
			umap[s[l]]--;
			if (umap[s[l]] == 0) umap.erase(s[l]);
			if (umap[s[l]] == k-1) cnt--;
		}
		return ret;
	}

	// divide and conquer
	int longestSubstring_divide(string s, int k) {
		unordered_map<char, int> umap;
		for (auto c : s) {
			umap[c]++;
		}
		bool isOK = true;
		for(auto item : umap) {
			if (item.second < k) {
				isOK=false; break;
			}
		}
		if (isOK) return s.size();
		int ret = 0, r = 0;
		for (int l = 0; l < s.size(); ++l) {
			if (umap[s[l]] < k) continue;
			while (r < s.size() && umap[s[r]] >= k) {
				++r;
			}
			// the substring between l and r is a candidate
			string subStr = s.substr(l, r-l);
			ret = max(r-l, longestSubstring_divide(subStr, k));
			l = r;
		}
		return ret;
	}


};

int main(int argc, char const *argv[])
{
	Solution s;
	// aaa, 3; ababb 5;
	string s1 = "aaabb", s2 = "ababbc"; 

	cout << s.longestSubstring_divide(s1, 3) << endl;
	cout << s.longestSubstring_divide(s2, 2) << endl;

	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:

	// 至多包含k个不同字符的最长字符串
	int lengthOfLongestSubstringKDistinct(string& s, int k) {
		int res = 0, left = 0;
		unordered_map<char, int> umap;
		for (int i = 0; i < s.size(); ++i) {
			umap[s[i]] += 1;
			while (umap.size() > k) {
				if (--umap[s[left]] == 0) {
					umap.erase(s[left]);
				}
				++left;
			}
			res = max(res, i - left + 1);
		}
		return res;
	}

	void showMap(unordered_map<char, int> umap) {
		for(auto item : umap) {
			cout << item.first << ", " << item.second << endl;
		}
	}



	int lengthOfLongestSubstringKDistinct_to(string& s, int k) {
		int max_len = 0, n = s.size(), n_diff = 0;
		int left = 0, right = 1;
		while (left < right && right <= n) {
			string str = s.substr(left, right - left);
			n_diff = numDifferent(str);
			// cout << "l: " << left << ", r: " << right << ", diff: " << n_diff << endl;
			// cout << str << endl;
			if (n_diff <= k) {
				max_len = max(max_len, right - left);
				++right;
			} else {
				++left;
			}
		}
		return max_len;
	}

	int numDifferent(string str) {
		unordered_map<char, int> umap;
		for (auto c : str) {
			umap[c] += 1;
		}
		return umap.size();
	}
	
};

int main(int argc, char const *argv[])
{
	string str = "eceba"; // "aa";
	int k = 2;
	Solution s;
	cout << s.lengthOfLongestSubstringKDistinct(str, k) << endl;

	return 0;
}
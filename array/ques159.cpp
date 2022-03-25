#include <stdlib.h>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstringTwoDistinct(string& s) {
		unordered_map<char, int> umap;
		int res = 0, n = s.size(), left = 0;

		for (int i = 0; i < n; ++i) {
			/* code */
			++umap[s[i]];
			while(umap.size() > 2) {
				if(--umap[s[left]] == 0){
					umap.erase(s[left]);
				}
				++left;
			}
			res = max(res, i - left + 1);
		}
		return res;
	}
	
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str = "ccaabbb";
	cout << s.lengthOfLongestSubstringTwoDistinct(str) << endl;

	return 0;
}
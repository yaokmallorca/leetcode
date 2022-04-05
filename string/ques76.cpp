#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{
public:
	string minWindow(string s, string t) {

		unordered_map<char, int> tmap, smap;
		for (auto c : t) tmap[c]++;
		int l = 0, cnt = 0, min_len = INT_MAX;
		string ret = "";
		int t_size = tmap.size();

		for (int r = 0; r < s.size(); ++r) {
			smap[s[r]]++;
			if (smap[s[r]] == tmap[s[r]]) ++cnt;
			// cout << "r: " << s[r] << ", " << smap[s[r]] 
			// 	 << ", " << tmap[s[r]] << ", " << cnt << ", " << tmap.size() << endl;
			while (cnt == t_size) {
				if ((r-l+1) < min_len) {
					min_len = r-l+1;
					ret = s.substr(l, r-l+1);
				}
				smap[s[l]]--;
				if (smap[s[l]] == (tmap[s[l]] - 1)) cnt--;
				l++;
			}
		}
		return ret;

	}
	
};

int main(int argc, char const *argv[])
{
	string s = "ADOBECODEBANC", t = "ABC";
	Solution solution;
	cout << solution.minWindow(s, t) << endl;
	return 0;
}
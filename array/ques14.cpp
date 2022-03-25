#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:

	string longestCommonPrefix(std::vector<string>& strs) {
		if (strs.empty()) return "";
		string res = "";
		for (int i = 0; i < strs[0].size(); ++i) {
			/* code */
			char c = strs[0][i];
			for (int j = 1; j < strs.size(); ++j) {
				/* code */
				if (j>=strs[i].size() || strs[j][i] != c) {
					return res;
				}

			}
			res.push_back(c);
		}
		return res;
	}


};

int main(int argc, char const *argv[])
{
	std::vector<string> strs = {"flower","flow","flight"};
	// {"flower","flow","flight"};
	Solution s;
	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}
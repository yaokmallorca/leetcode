#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {

public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return {};
		vector<string> res;
		vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		letterCombinationsPDF(digits, dict, 0, "", res);
		return res;
	}

	void letterCombinationsPDF(string& digits, vector<string>& dict, int level, string out, vector<string>& res) {
		if (level == digits.size()) {res.push_back(out); return;}
		string str = dict[digits[level] - '0'];
		for (int i=0; i<str.size(); i++) {
			letterCombinationsPDF(digits, dict, level+1, out+str[i], res);
		}
	}
};

int main() {
	string digits = "23";
	Solution s;
	vector<string> result = s.letterCombinations(digits);
	for(std::vector<string>::iterator it=result.begin(); it!=result.end(); it++) {
		cout << it->c_str() << endl;
	}

	return 0;
}
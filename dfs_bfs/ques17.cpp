#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;;

class Solution
{
public:
	std::vector<string> tele_dict;

public:
	Solution() {
		tele_dict = {"", "", "abc", "def",
					"ghi", "jkl", "mno", "pqrs",
					"tuv", "wxyz"};
	}

	std::vector<string> letterCombination(string digits) {
		if (digits.empty()) return {};
		std::vector<string> res;
		int level = 0;
		string str = "";
		letterCombinationDFS(digits, res, level, str);
		return res;
	}
	
	void letterCombinationDFS(string digits, std::vector<string>& res, int level, string str) {
		if (level == digits.size()) {res.push_back(str); return;}
		int pos = digits[level] - '0';
		for (auto letter : tele_dict[pos]){
			letterCombinationDFS(digits, res, level+1, str+letter);
		}
	}

	template<typename T> 
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << endl;
		}
	}
};


int main(int argc, char const *argv[])
{
	string digits = "23";
	Solution s;
	std::vector<string> results = s.letterCombination(digits);
	s.showVec(results);
	return 0;
}
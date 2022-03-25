#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	std::vector<string> removeInvalidParenthese(string& s) {
		std::vector<string> res; 
		int cnt_left_p = 0, cnt_right_p = 0;
		for (char c : s) {
			cnt_left_p += (c == '(');
			if (cnt_left_p == 0) cnt_right_p += (c == ')');
			else cnt_left_p -= (c == ')');
		}
		helper(s, 0, cnt_left_p, cnt_right_p, res);
		return res;
	}

	void helper(string s, int start, int cnt_left_p, int cnt_right_p, std::vector<string>& res) {
		if (cnt_left_p == 0 && cnt_right_p == 0) {
			if (isValid(s)){ 	
				cout << s << endl;
				res.push_back(s); 
			}
			return;
		}
		for (int i = start; i < s.size(); ++i) {
			if (i != start && s[i] == s[i - 1]) continue;
			if (cnt_left_p > 0 && s[i] == '(') {
				string s_str = s.substr(0, i) + s.substr(i+1);
				// cout << s_str << endl;
				helper(s_str, i, cnt_left_p-1, cnt_right_p, res);
			}
			if (cnt_right_p > 0 && s[i] == ')') {
				string s_str = s.substr(0, i) + s.substr(i+1);
				// cout << s_str << endl;
				helper(s_str, i, cnt_left_p, cnt_right_p-1, res);
			}
		}
	}

	bool isValid(string t) {
		int cnt = 0;
		for (int i = 0; i < t.size(); ++i) {
			/* code */
			if (t[i] == '(') ++cnt;
			else if (t[i] == ')' && --cnt < 0) return false;
		}
		return cnt == 0;
	}

	void showVec(std::vector<string>& strs) {
		for (auto str : strs) {
			cout << str << endl;
		}
	}
	
};

int main(int argc, char const *argv[])
{
	// string str = "()())()";
	string str = "(a)())()";
	Solution s;
	std::vector<string> res = s.removeInvalidParenthese(str);
	cout << "<<<<<<<<<<<<<<<<<<<<<" << endl;
	s.showVec(res);
	return 0;
}
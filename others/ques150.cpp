#include <iostream>
#include <string>
#include <cstring> // strcmp
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <map>
#include <climits>
#include <iterator> // iterator
#include <algorithm> // reverse
#include <utility> // pair

using namespace std;

class Solution
{
public:
	int evalRPN1(std::vector<string>& token) {
		if (token.size() < 3) return stoi(token[0]);
		int n = token.size();
		int pos = 0;
		while (pos < n) {
			if(token[pos] == "+" || token[pos] == "-" || 
			   token[pos] == "*" || token[pos] == "/" ) {
				break;
			}
			++pos;
		}
		pos -= 1;
		if (pos < token.size() && (token[pos+1] == "+" || token[pos+1] == "-"
			|| token[pos+1] == "*" || token[pos+1] == "/")) {
			int val = 0;
			if (token[pos+1] == "+") val = stoi(token[pos-1]) + stoi(token[pos]);
			if (token[pos+1] == "-") val = stoi(token[pos-1]) - stoi(token[pos]);
			if (token[pos+1] == "*") val = stoi(token[pos-1]) * stoi(token[pos]);
			if (token[pos+1] == "/") val = stoi(token[pos-1]) / stoi(token[pos]);
			token[pos] = to_string(val);
			token.erase(token.begin() + (pos-1));
			token.erase(token.begin() + pos);
		}
		evalRPN1(token);
		return stoi(token[0]);
	}

	int evalRPN(std::vector<string>& tokens) {
		int op = (int) tokens.size() - 1;
		return helper(tokens, op);
	}

	int helper(std::vector<string>& tokens, int& op) {
		string str = tokens[op];
		if (str != "+" && str != "-" && str != "*" && str != "/") return stoi(str);
		int num1 = helper(tokens, --op);
		int num2 = helper(tokens, --op);
		if (str == "+") return num2 + num1;
		if (str == "-") return num2 - num1;
		if (str == "*") return num2 * num1;
		return num2 / num1;
	}

	void showVec(std::vector<string> vec) {
		for (auto str : vec) {
			cout << str.c_str() << " ";
		}
		cout << endl;
	}
};

/*
10 6 9 3 + -11 * / * 17 + 5 + 
10 6 12 -11 * / * 17 + 5 + 
10 6 -132 / * 17 + 5 + 
10 0 * 17 + 5 + 
0 17 + 5 + 
17 5 + 
22 

*/

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<string> input_arr = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	s.showVec(input_arr);
	// int pos = 3;
	// input_arr[pos] = to_string(stoi(input_arr[pos-1])+stoi(input_arr[pos]));
	// input_arr.erase(input_arr.begin() + (pos - 1));
	// s.showVec(input_arr);
	// input_arr.erase(input_arr.begin() + pos);
	// s.showVec(input_arr);
	int res = s.evalRPN(input_arr);
	cout << "res: " << res << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <stack>
#include <queue> 
#include <numeric> // accumulate

using namespace std;

class Solution
{
public:
	void showVec(std::vector<string> strs) {
		for (auto str : strs) {
			cout << str.c_str() << " ";
		}
		cout << endl;
	}

	// 22 generate parenthesis
	std::vector<string> generateParenthesis(int n) {
		std::vector<string> res;
		generateParenthesisBT(n, n, "", res);
		return res;
	}

	void generateParenthesisBT(int left, int right, string str, std::vector<string>& res) {
		if (left > right) {
			cout << "111 left: " << left << ", right: " << right << ", str: " << str.c_str() << endl;
			return;}
		if (left == 0 && right == 0) {
			cout << "222 left: " << left << ", right: " << right << ", str: " << str.c_str() << endl;
			res.push_back(str);}
		else {
			cout << "333 left: " << left << ", right: " << right << ", str: " << str.c_str() << endl;
			if (left > 0) generateParenthesisBT(left - 1, right, str + '(', res);
			if (right > 0) generateParenthesisBT(left, right - 1, str + ')', res);
		}
	}
};

int main() {
	Solution s;
	int n = 3;
	std::vector<string> result_ques22 = s.generateParenthesis(n);
	s.showVec(result_ques22);

}
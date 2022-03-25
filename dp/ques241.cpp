#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	/*
	(((2*3-4*5)))
	((2*(3-4*5)))
	((2*3-(4*5)))
	((2*3-4*(5)))

	*/
	std::vector<int> diffWaysToCompute(string expression) {
		std::vector<int> res;
		int n = expression.size();
		for (int i = 0; i < expression.size(); ++i) {
			/* code */
			if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
				std::vector<int> left  = diffWaysToCompute(expression.substr(0, i));
				std::vector<int> right = diffWaysToCompute(expression.substr(i+1));
				for (auto l : left) {
					for (auto r : right) {
						if (expression[i] == '+') { res.push_back(l + r); }
						if (expression[i] == '-') { res.push_back(l - r); }
						if (expression[i] == '*') { res.push_back(l * r); }
					}
				} 
			}
		}
		// if (res.empty()) res.push_back(stoi(expression));
		return res;
	}


	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

};

int main(int argc, char const *argv[]) {
	string str = "2-1-1";
	Solution s;
	std::vector<int> res = s.diffWaysToCompute(str);
	s.showVec(res);
	return 0;
}
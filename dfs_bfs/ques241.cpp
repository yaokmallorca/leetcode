#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string> 
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> diffWaysToCompute(string expression) {
		if (umap.count(expression)) return umap[expression];
		vector<int> res;
		int n = expression.size();
		for (int i = 0; i < n; ++i) {
			/* code */
			if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
				std::vector<int> left = diffWaysToCompute(expression.substr(0, i));
				std::vector<int> right = diffWaysToCompute(expression.substr(i+1));

				for (auto l : left) {
					for (auto r : right) {
						if (expression[i] == '+') res.push_back((l)+(r));
						if (expression[i] == '-') res.push_back((l)-(r));
						if (expression[i] == '*') res.push_back((l)*(r));
					}
				}
			}
		}
		if (res.empty()){
			// cout << "exp: " << expression << endl;
			res.push_back(stoi(expression));
		}
		return res;
	}

	void showVec(string name, std::vector<int> nums) {
		cout << name << " : ";
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

private:
	unordered_map<string, std::vector<int> > umap;
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str = "2*3-4*5";
	std::vector<int> res = s.diffWaysToCompute(str);
	cout << res.size() << endl;
	s.showVec("res", res);
	return 0;
}
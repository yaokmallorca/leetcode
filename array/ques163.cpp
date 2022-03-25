#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	std::vector<string> findMissingRanges(std::vector<int> nums, int low, int high) {
		std::vector<string> res;
		for (auto num : nums) {
			if (num > low) {
				if (num > low +1)
					res.push_back(to_string(low) + "->" + to_string(num-1));
				else
					res.push_back(to_string(low));
			}
			if (num == upper) return res;
			low = num+1;
		}

		if (low <= high) res.push_back(to_string(low) + (high > low ? ("->" + to_string(high)) : ""));
		return res;
	}

	/*
	vector<string> res;
	for (int num : nums) {
		if (num > lower) res.push_back(to_string(lower) + (num - 1 > lower ? ("->" + to_string(num - 1)) : ""));
		if (num == upper) return res;
		lower = num + 1;
	}
	if (lower <= upper) res.push_back(to_string(lower) + (upper > lower ? ("->" + to_string(upper)) : ""));
	return res;
	*/

	void showVec(std::vector<string> strs) {
		for (auto str : strs)
			cout << str << " ";
		cout << endl;
	}

};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> nums = {0, 1, 3, 50, 75};
	std::vector<string> res = s.findMissingRanges(nums, 0, 99);
	s.showVec(res);


	return 0;
}
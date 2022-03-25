#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<int> > merge1(std::vector< std::vector<int> >& interals) {
		// if (interals.size() <= 1) return interals.empty() ? {} : interals[0];
		std::vector< std::vector<int> > res;
		for (int i = 1; i < interals.size(); ++i) {
			/* code */
			std::vector<int> num1, num2;
			num1 = res.size() == 0 ? interals[i-1] : res.back();
			num2 = interals[i];
			showVec(num1);
			showVec(num2);
			if (num1[1] > num2[0] && num1[1] <= num2[1]) {
				// res.push_back({num1[0], num2[1]});
				if (res.size() == 0) res.push_back({num1[0], num2[1]});
				else res.back()[1] = num2[1];
			} else if (num1[1] > num2[0] && num1[1] > num2[1]) {
				if (res.size() == 0) res.push_back(num1);
			} else {
				res.push_back(num2);
			}
			showVec(res);
			cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		}
		return res;
	}

	std::vector< std::vector<int> > merge(std::vector< std::vector<int> >& interals) {
		if (intervals.empty()) return {};
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res{intervals[0]};
		for (int i = 1; i < intervals.size(); ++i) {
			if (res.back()[1] < intervals[i][0]) {
				res.push_back(intervals[i]);
			} else {
				res.back()[1] = max(res.back()[1], intervals[i][1]);
			}
		}   
		return res;

	}

	template<typename T>
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	template<typename T>
	void showVec(std::vector< std::vector<T> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}
};

int main(int argc, char const *argv[])
{
	std::vector< std::vector<int> > nums =  {{1,4},{4,5}}; // {{1,3},{2,6},{8,10},{15,18}};
	Solution s;
	std::vector< std::vector<int> > res = s.merge(nums);
	s.showVec(res);

	return 0;
}
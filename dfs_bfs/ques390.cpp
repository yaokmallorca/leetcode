#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int lastRemaining(int n) {
		int res = 0;
		// std::vector<int> arr;
		std::vector<int> nums;
		for (int i = 1; i <= n; ++i) {
			/* code */
			nums.push_back(i);
		}
		std::vector< std::vector<int> > arrs;
		bool left2right = true;
		lastRemainingDFS(nums, left2right, arrs);
		showVec(arrs);
		return arrs.size();
	}

	void lastRemainingDFS(std::vector<int> nums, bool& left2right, std::vector< std::vector<int> >& arrs) {
		if (nums.size() <= 1) return; 
		std::vector<int> arr;
		if (left2right){
			for (int i=1; i<nums.size(); i+=2) {
				arr.push_back(nums[i]);
			}
			left2right = false;
		} else {
			for (int i=nums.size()-1; i>=1; i-=2) {
				arr.push_back(nums[i-1]);
			}
			left2right = true;
		}
		arrs.push_back(arr);
		lastRemainingDFS(arr, left2right, arrs);
	}
	
	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	void showVec(std::vector< std::vector<int> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}

	int help(int n, bool left2right) {
		if (n == 1) return 1;
		if (left2right) {
			return 2 * help(n / 2, false);
		} else {
			return 2 * help(n / 2, true) - 1 + n % 2;
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int n = 9, res = 0;
	res = solution.lastRemaining(n);
	return 0;
}
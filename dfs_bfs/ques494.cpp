#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int res = 0;
		helper(nums, 0, 0, target, res);
		return res;

	}
	

	void helper(std::vector<int>& nums, int start, int cur, int target, int& res) {
		if (start >= nums.size()) {
			if (cur == target) ++res; 
			return;
		}
		helper(nums, start+1, cur+nums[start], target, res);
		helper(nums, start+1, cur-nums[start], target, res);
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {1,1,1,1,1};
	Solution s;
	cout << s.findTargetSumWays(nums, 3) << endl;
	

	return 0;
}
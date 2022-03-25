#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
	/*
	int maxProduct(std::vector<int>& nums) {
		int n = nums.size(), res = 0;
		std::vector<int> max_num(n, INT_MIN);
		std::vector<int> min_num(n, INT_MAX);
		max_num[0] = nums[0];
		min_num[0] = nums[0];

		for (int i = 1; i < n; ++i) {
			max_vals[i] = max( max(max_vals[i-1]*nums[i], nums[i]), min_vals[i-1]*nums[i] );
			min_vals[i] = min( min(max_vals[i-1]*nums[i], nums[i]), min_vals[i-1]*nums[i] );
			res = max(res, max_vals[i]);
		}
		return res;
	}
	*/

	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty()) return 0;
		int left = 0, right = 0, n = nums.size(), cur = 0;
		int res = INT_MAX;
		while (right < n) {
			while (cur < s && right < n) {
				cur += nums[right];
			}
			while (sum >= s) {
				res = min(res, right - left);
				sum -= nums[left++];
			}
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {2,3,1,2,4,3};
	Solution s;
	cout << s.minSubArrayLen(7, nums) << endl;

	return 0;
}
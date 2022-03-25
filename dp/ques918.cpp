#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:

	// max(max_subarray, sum - min_subarray)
	int maxSubarraySumCircle(std::vector<int> nums) {
		int res=INT_MIN, sum=0;
		int cur_sum = 0, min_val=INT_MAX, max_val=INT_MIN;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			/* code */
			cur_sum = max(cur_sum + nums[i], nums[i]);
			max_val = max(max_val, cur_sum);
			cur_sum = 0;
			cur_sum = min(cur_sum + nums[i], nums[i]);
			min_val = min(min_val, cur_sum);
			sum += nums[i];
		}
		if (min_val == sum) return max_val;
		return max(max_val, sum-min_val);
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {3, -2, 2, -3}; // {3,-1,2,-1};
	Solution s;
	int res = s.maxSubarraySumCircle(nums);
	cout << "result: " << res << endl;

	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
	// cur_prod = max(cur_prod * nums[i], nums[i])
	int maxProduct(std::vector<int> nums) {
		int n = nums.size();
		std::vector<int> max_vals(n, INT_MIN);
		std::vector<int> min_vals(n, INT_MAX);
		max_vals[0] = nums[0];
		min_vals[0] = nums[0];
		int res = nums[0];

		for (int i = 1; i < n; ++i) {
			/* code */
			max_vals[i] = max( max(min_vals[i-1]*nums[i], nums[i]), max_vals[i-1]*nums[i]);
			min_vals[i] = min( min(min_vals[i-1]*nums[i], nums[i]), max_vals[i-1]*nums[i]);
			res = max(res, max_vals[i]);
		}
		return res;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {2, 0, -1}; // {2,3,-2,4}; 
	Solution s;
	int res = s.maxProduct(nums);
	cout << "res: " << res << endl;
	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int left=0, right=0, res = INT_MAX, t=0;
		for(; right<nums.size(); ++right) {
			t += nums[right];
			if (t < s) {
				continue;
			} else {
				while (t >= s) {
					res = min(res, right - left + 1);
					t -= nums[left];
					++left;
				}
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
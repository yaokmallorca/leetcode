#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution
{
public:
	// nums[i] + nums[j] + nums[k] < target
	int threeSumSmaller(std::vector<int>& nums, int target) {
		int res = 0, n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = n-1; i>=0; --i) {
			int left = 0, right = i-1;
			while (left < right) {
				if (nums[left] + nums[right] + nums[i] < target) {
					res += right-left; 
					++left;
				} else {
					--right;
				}
			}
		}
		return res;
	}
	
};

int main(int argc, char const *argv[])
{

	// 2
	std::vector<int> nums = {-2, 0, 1, 3};
	Solution s;
	cout << s.threeSumSmaller(nums, 2) << endl;

	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int trap(std::vector<int>& nums) {
		int res = 0; // n = nums.size();
		int left = 0, right = nums.size()-1;
		while (left < right) {
			int min_val = min(nums[left], nums[right]);
			if (min_val == nums[left]) {
				// scan from left
				++left;
				while (left < right && nums[left] < min_val) {
					res += min_val - nums[left++];
				}
			} else {
				// scan from right
				--right;
				while(left < right && nums[right] < min_val) {
					res += min_val - nums[right--];
				}
			}

		}
		return res;
	}

};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1}; // 6
	Solution s;
	cout << s.trap(nums) << endl;
	return 0;
}

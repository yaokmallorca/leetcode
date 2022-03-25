#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool canJump(std::vector<int>& nums) {
		int n = nums.size();
		int farest_pos = 0;
		for (int i = 0; i < n; ++i) {
			if (i > farest_pos) return false;
			farest_pos = max(i + nums[i], farest_pos);
		}
		return true;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {2,3,1,1,4}; // {3,2,1,0,4};
	// std::vector<int> nums = {3,2,1,0,4};
	Solution s;

	cout << s.canJump(nums) << endl;
	return 0;
}
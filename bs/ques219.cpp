#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			cout << nums[left] << ", " << nums[right] << ", " << left << ", " << right << endl;
			if (nums[left] == nums[right] && abs(left-right)<=k) return true;
			if (nums[left] < nums[right]) ++left;
			else --right;
		}
		return false;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {1,0,1,1}; // {1,2,3,1};
	Solution s;
	bool res = s.containsNearbyDuplicate(nums, 1);
	cout << "res: " << res << endl;
	return 0;
}

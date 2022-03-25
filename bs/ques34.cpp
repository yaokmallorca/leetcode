#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	std::vector<int> searchRange(std::vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		int pos = 0;
		std::vector<int> res;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if(nums[mid] == target) {pos = mid; break;}
			if(nums[mid] < target) {
				left = mid - 1;
			} else {
				right = mid;
			}
		}
		res.push_back(pos);
		if (nums[pos] == nums[pos+1]) {res.push_back(pos+1);}
		if (nums[pos-1] == nums[pos]) {
			if (res.size() > 1) res.pop_back();
			res.push_back(pos-1);
		}
		return res;
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
	
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> nums = {5,7,7,8,8,10};
	std::vector<int> res = s.searchRange(nums, 8);
	s.showVec(res);
	return 0;
}
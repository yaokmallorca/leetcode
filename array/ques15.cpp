#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<int> > threeSum(std::vector<int>& nums) {	
		std::vector< std::vector<int> > res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size()-2; ++i) {
			/* code */
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int target = nums[i];
			int left = i+1, right = nums.size()-1;
			while (left < right) {
				int tmp = nums[left] + nums[right];
				if (tmp + target == 0) {
					res.push_back({nums[i], nums[left], nums[right]});
					while (left < right && nums[left] == nums[left+1]) ++left;
					while (left < right && nums[right] == nums[right+1]) --right;
					++left; --right;
				} else if (tmp + target < 0) {
					++left;
				} else {
					--right;
				}
			}
		}
		return res;
	}
	

	template<typename T>
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	template<typename T>
	void showVec(std::vector< std::vector<T> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {-1,0,1,2,-1,-4};
	Solution s;
	std::vector< std::vector<int> > res = s.threeSum(nums);
	s.showVec(res);
	return 0;
}
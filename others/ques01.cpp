#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		int len = nums.size();
		std::vector<int> res;
		for (int i = 0; i < len; ++i) {
			for(int j = i+1; j<len; ++j) {
				/* code */
				int sum = nums[i] + nums[j];
				if (sum == target) {
					res.push_back(i);
					res.push_back(j);
					return res;
				}
			}
		}
		return res;
	}
	
	void show_vec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> nums = {3,2,3};
	std::vector<int> results = s.twoSum(nums, 6);
	s.show_vec(results);
	return 0;
}
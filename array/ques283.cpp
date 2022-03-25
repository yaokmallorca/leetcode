#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	void moveZeroes(std::vector<int>& nums) {
		if (nums.empty()) return;
		for(int i=0, j=0; i<nums.size(); ++i) {
			cout << i << ", " << j << endl;
			cout << nums[i] << ", " << nums[j] << endl;
			if (nums[i]!=0) {
				swap(nums[i], nums[j++]);
			}
			cout << i << ", " << j << endl;
			showVec(nums);
		}

	}

	void showVec(std::vector<int>& nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
		cout << "<<<<<<<<<<<<<<<<<<" << endl;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {0,1,0,3,12};
	Solution s;
	s.moveZeroes(nums);
	s.showVec(nums);
	return 0;
}

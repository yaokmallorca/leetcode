#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
		if (nums.empty()) return {};
		std::vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			/* code */
			int idx = abs(nums[i]) - 1;
			nums[idx] = nums[idx]>0 ? -nums[idx] : nums[idx];
		}
		for (int i = 0; i < nums.size(); ++i) {
			/* code */
			if (nums[i] > 0) res.push_back(i+1);
		}
		return res;
	}
	
	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	// ques 461 hamming distance
	int hammingDistance(int x, int y) {
		int res = 0;
		for (int i = 0; i < 32; ++i) {
			/* code */
			if ( (x & (1 << i)) ^ (y & (1 << i)) )
				++res;
		}
		return res;
	}

};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> nums = {4,3,2,7,8,2,3,1};
	std::vector<int> res = s.findDisappearedNumbers(nums);
	s.showVec(res);


	cout << "hamming: " << s.hammingDistance(4, 1) << endl;
	return 0;
}
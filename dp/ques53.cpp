#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
	int maxSubArray(std::vector<int>& nums) {
		int max_sum = INT_MIN, cur_sum = 0; 
		for (auto num : nums) {
			cur_sum = max(num, cur_sum+num);
			max_sum = max(cur_sum, max_sum);
		}
		return max_sum;
	}


	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
	
};

int main(int argc, char const *argv[]) {
	/* code */
	std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	s.showVec(nums);
	int res = s.maxSubArray(nums);
	cout << "res: " << res << endl;
	return 0;
}
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
	int findPairs(vector<int>& nums, int k) {
		int res = 0, pre = INT_MAX, j = 0; 
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); ++i){
			while (j < i && nums[i] - nums[j] > k) ++j;
			if (j != i && pre != nums[j] && nums[i] - nums[j] == k) {
				++res;
				pre = nums[j];
			}
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums1 = {1, 3, 1, 5, 4};
	std::vector<int> nums2 = {1, 2, 3, 4, 5};
	std::vector<int> nums3 = {1, 3, 1, 5, 4}; 
	Solution s;
	cout << s.findPairs(nums1, 2) << endl;
	cout << s.findPairs(nums2, 1) << endl;
	cout << s.findPairs(nums3, 0) << endl;
	return 0;
}
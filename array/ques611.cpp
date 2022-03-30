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
	// 超时
	int ValidTriangle1(std::vector<int>& nums) {
		int res = 0, n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i=0; i <= n-3; ++i) {
			for (int j=i+1; j<n; ++j) {
				int target = nums[i] + nums[j];
				int left = j+1, right = n;
				while (left < right) {
					int mid = left + (right - left) / 2;
					if (nums[mid] < target) left = mid+1;
					else right = mid;
				}
				res += right-j-1;
			}
		}
		return res;
	}

	int ValidTriangle(std::vector<int>& nums) {
		int res = 0;
		sort(nums.begin(), nums.end());
		// for (int i = 0; i < nums.size(); ++i) {
		for (int i=nums.size()-1; i>=0; --i) {
			/* code */
			int left = 0, right = i-1;
			while (left < right) {
				if (nums[i] < nums[left] + nums[right]) {
					res += right - left;
					--right;
				} else {
					++left;
				}
			}
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	// 3 -> 223, 234
	std::vector<int> nums = {2,2,3,4};
	Solution s;

	cout << s.ValidTriangle(nums) << endl;


	return 0;
}
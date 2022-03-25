#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	// int lengthOfLIS(std::vector<int>& nums, std::vector< std::vector<int> >& vecs) {
	// O(n^2)
	std::vector< std::vector<int> > lengthOfLIS(std::vector<int>& nums) {
		std::vector< std::vector<int> > res;
		int max_len = 0, n = nums.size();

		for (int i = 0; i < n; ++i) {
			/* code */
			int mx = nums[i];
			int cur_len = 0;
			std::vector<int> sub_arr;
			for (int j = i; j < n; ++j) {
				mx = max(mx, nums[j]);
				if (mx == nums[j]) {
					++cur_len;
					sub_arr.push_back(nums[j]);
				}
			}
			max_len = max(max_len, cur_len);
			res.push_back(sub_arr);
		}
		// cout << "max length: " << max_len << endl;
		// showVec(res);
		return res;
	}
	

	// 
	int lengthOfLIS_faster(std::vector<int>& nums) {
		std::vector<int> dp;
		for (int i = 0; i < nums.size(); ++i) {
			/* code */
			int left = 0, right = dp.size();
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (dp[mid] < nums[i]) {
					left = mid + 1;
				} else {
					right = mid;
				}
			}
			showVec(dp);
			if (right >= dp.size()) dp.push_back(nums[i]);
			else dp[right] = nums[i];
			showVec(dp);
			cout << "<<<<<<<<<<<<<<<<" << endl;
		}
		
		return dp.size();
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	void showVec(std::vector< std::vector<int> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {10,9,2,5,3,7,101,1};
	Solution s;
	s.showVec(nums);
	// std::vector< std::vector<int> > nums1 = s.lengthOfLIS(nums);
	cout << s.lengthOfLIS_faster(nums) << endl;
	// s.showVec(nums1);
	return 0;
}
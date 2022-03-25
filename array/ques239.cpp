#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	std::vector<int> maxSlidingWindow1(std::vector<int>& nums, int k) {
		if (k == 1) return nums;
		int left = 0, right = 0, n = nums.size();
		int cur_max = INT_MIN;
		std::vector<int> res;
		while (right < k) {
			cur_max = max(nums[right++], cur_max);
		}
		res.push_back(cur_max);

		while(right < n) {
			cur_max = max(nums[right], min(nums[left], nums[right]));
			res.push_back(cur_max);
			++left; ++right;
		}
		// res.push_back(cur_max);
		return res;
	}
	
	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}


	std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
		std::vector<int> res;
		multiset<int> st;
		for(int i=0; i<nums.size(); ++i) {
			if (i>=k) st.erase(st.find(nums[i-k]));
			st.insert(nums[i]);
			if (i >= k-1) res.push_back(*st.rbegin());
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
	// std::vector<int> nums = {7, 2, 4};
	std::vector<int> res = s.maxSlidingWindow(nums, 3);
	s.showVec(res);


	multiset<int> st;
	for (int i = 0; i < nums.size(); ++i) {
		/* code */
		st.insert(nums[i]);
	}
	for (auto num : st) {
		cout << num << ", ";
	}
	cout << endl;
	return 0;
}
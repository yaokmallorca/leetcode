#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std; 

class Solution
{
public:
	std::vector< std::vector<int> > twoSum1(std::vector<int>& nums, int target) {
		std::vector< std::vector<int> > res;
		int n = nums.size();
		for (int i=0; i<n; ++i) {
			int left = i+1, right = n, t = target - nums[i];
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (t == nums[mid]) {
					res.push_back({i, mid});
					break;
				} 
				else if (nums[mid] < t) left = mid + 1;
				else right = mid;
			}
		}
		return res;
	}


	std::vector< std::vector<int> > twoSum(std::vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		std::vector< std::vector<int> > res;
		while (l < r) {
			int sum = nums[l] + nums[r];
			if (sum == target) {
				res.push_back({l, r});
				++l; --r;
			} else if (sum < target) {
				++l;
			} else {
				--r;
			}
		}
		return res;
	}
	
	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " "; 
		}
		cout << endl;
	}

	void showVec(std::vector< std::vector<int> > nums) {
		for (auto num : nums ) {
			showVec(num);
		}
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {2,3,4}; // {3,24,50,79,88,150,345};
	Solution s;

	std::vector< std::vector<int> > res = s.twoSum(nums, 6);
	cout << "result: ";
	s.showVec(res);

	return 0;
}
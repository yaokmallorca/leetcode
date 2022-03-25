#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	/*
	int splitArray(std::vector<int>& nums, int m) {
		int n = nums.size();
		int max_val = 0, sum_val = 0;
		for (auto num : nums) {
			max_val = max(num, max_val);
			sum_val += num;
		}

		int left = max_val, right = sum_val;
		while (left < right) {
			int mid = left + (right - left) / 2;
			int num_sub_array = numSubArray(nums, mid);
			if (num_sub_array <= m) {
				right = mid;
			} else {
				left = mid + 1;
			} 
		}
		return left;
	}


	int numSubArray(std::vector<int> nums, int largest) {
		int res = 1;
		int tmp_sum = 0;
		for (auto num : nums) {
			tmp_sum += num;
			if (tmp_sum > largest) {
				++res;
				tmp_sum = num;
			}
		}
		return tmp_sum;
	}
	*/

	int numSubArray(std::vector<int> nums, long long largest) {
		int res = 1;
		long long tmp_sum = 0;
		for (auto num : nums) {
			tmp_sum += (long long)num;
			if (tmp_sum > largest) {
				++res;
				tmp_sum = (long long)num;
			}
		}
		return res;
	}

	int splitArray(vector<int>& nums, int m) {
		long left = 0, right = 0;
		for (int i = 0; i < nums.size(); ++i) {
			left = max(left, (long)nums[i]);
			right += nums[i];
		}
		while (left < right) {
			long long mid = left + (right - left) / 2;
			// if (can_split(nums, m, mid)) right = mid;
			// else left = mid + 1;
			int num_sub_array = numSubArray(nums, mid);
			if (num_sub_array <= m) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		return right;
	}

	bool can_split(vector<int>& nums, long m, long sum) {
		long cnt = 1, curSum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			curSum += nums[i];
			if (curSum > sum) {
				curSum = nums[i];
				++cnt;
				if (cnt > m) return false;
			}
		}
		return true;
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
	std::vector<int> nums = {7,2,5,10,8};
	int m = 2;
	Solution s;

	int res = s.splitArray(nums, m);
	cout << "res: " << res << endl;
	return 0;
}
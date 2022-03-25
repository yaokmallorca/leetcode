#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	// 从后往前，第一个下降的数字i,然后往后找到第一个大于数字i-1的数字j,
	// swap(nums[i], nums[j])
	// 最后reverse from i to n

	void nextPermutation(std::vector<int>& nums) {
		int n = nums.size(), i = n-2, j=n-1;
		while(i>0 && nums[i]>=nums[i+1]) --i;
		cout << "i = " << i << ", nums[i] = " << nums[i] << endl;
		while(j>i && nums[j]<=nums[i]) --j;
		cout << "j = " << j << ", nums[j] = " << nums[j] << endl;
		swap(nums[i], nums[j]);
		reverse(nums.begin()+i+1, nums.end());
	}

	int numScores(std::vector<int> nums) {
		int res = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			/* code */
			res += nums[i] * 10;
		}
		return res;
	}

	template<typename T> 
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
	

	template<typename T> 
	void showVec(std::vector< std::vector<T> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}

	void nextPermutation1(std::vector<int>& nums) {
		if (nums.size() <= 1) return;
		// 从后往前，第一个下降的数字i,然后往后找到第一个大于数字i的数字j,
		// swap(nums[i], nums[j])
		// 最后reverse from i to n

		int n = nums.size(), i = n - 2, j = n - 1;
		while (i >= 0 && nums[i] >= nums[i + 1]) --i;
		cout << "i: " << i << ", nums[i]: " << nums[i] << endl;
		if (i >= 0) {
			while (nums[j] <= nums[i]) --j;
			cout << "j: " << j << ", nums[j]: " << nums[j] << endl;
			swap(nums[i], nums[j]); 
		}
		showVec(nums);
		reverse(nums.begin() + i + 1, nums.end());
	}

};

int main(int argc, char const *argv[])
{
	std::vector<int> nums1 = {1, 2, 7, 4, 3, 1};
	std::vector<int> nums2 = {1, 2, 7, 4, 3, 1};
	// 1 3 1 2 4 7
	Solution s;
	s.showVec(nums1);
	s.nextPermutation(nums1);
	s.showVec(nums1);

	cout << "<<<<<<<<<<<<<<<<<<<" << endl;

	s.nextPermutation1(nums2);
	s.showVec(nums2);
	return 0;
}
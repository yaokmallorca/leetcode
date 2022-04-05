#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	std::vector<int> merge(std::vector<int>& nums1, std::vector<int>& nums2) {
		if (nums1.empty() && nums2.empty()) return {};
		if (nums1.empty() || nums2.empty()) return (nums1.empty()) ? nums2 : nums1;
		int m = nums1.size(), n = nums2.size(), i=0, j=0;
		std::vector<int> res;

		while (i<m && j<n) {
			if (nums1[i] < nums2[j]) {
				res.push_back(nums1[i++]);
			} else {
				res.push_back(nums2[j++]);
			}
		}
		while (i<m) res.push_back(nums1[i++]);
		while (j<n) res.push_back(nums2[j++]);
		return res;
	}
	

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums1 = {1,3,6,8,8};
	std::vector<int> nums2 = {2,4,6,9};
	Solution s;

	s.showVec(nums1); s.showVec(nums2);
	std::vector<int> res = s.merge(nums1, nums2);
	s.showVec(res);
	return 0;
}
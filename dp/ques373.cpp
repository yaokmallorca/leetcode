#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<int> > kSmallestPairs(std::vector<int>& nums1, 
		std::vector<int>& nums2, int k) {
		std::vector< std::vector<int> > res;
		for (int i=0; i<min(nums1.size(), k); ++i) {
			for (int j=0; j<min(nums2.size(), k); ++j) {
				res.push_back({nums1[i], nums2[j]});
			}
		}

		sort(res.begin(), res.end(), )
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
	std::vector<int> nums1 = {1,7,11};
	std::vector<int> nums2 = {2,4,6};
	int k = 3;
	Solution s;
	std::vector< std::vector<int> > res = s.kSmallestPairs(nums1, nums2, k);
	s.showVec(res);
	return 0;
}
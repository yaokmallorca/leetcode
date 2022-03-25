#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
	// brute force
	std::vector< std::vector<int> > kSmallestPair_bf(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
		std::vector< std::vector<int> > res; 
		int cnt = 0;
		for (auto num1 : nums1) {
			for (auto num2 : nums2) {
				res.push_back({num1, num2});
			}
		}
		sort(res.begin(), res.end(), compare_vector);
		if (res.size() > k) res.erase(res.begin()+k, res.end());
		return res;
	}

	std::vector< std::vector<int> > kSmallestPair(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
		std::vector< std::vector<int> > res;
		int ind1 = 1, ind2 = 1;
		res.push_back({nums1[0], nums2[0]});
		int sum_prev = INT_MAX;

		while (ind1 < nums1.size() && ind2 < nums2.size() && res.size() < k) {
			int sum1 = nums1[ind1-1] + nums2[ind2];
			int sum2 = nums2[ind2-1] + nums1[ind1];
			int sum_min = 0;
			if (sum1 < sum2) {
				sum_min = sum1;
			} else {
				sum_min = sum2;
			}

			if (sum_min < sum_prev) {
				sum_prev = sum_min;
			}







		}



	}

	static bool compare_pair(pair<int, int> pair1, pair<int, int> pair2) {
		return pair1.first + pair1.second < pair2.first + pair2.second;
	}

	static bool compare_vector(std::vector<int> nums1, std::vector<int> nums2) {
		int sum1 = 0, sum2 = 0;
		for(auto num1 : nums1) {
			sum1 += num1;
		}
		for(auto num2 : nums2) {
			sum2 += num2;
		} 
		return sum1 < sum2;
	}

	void showPair(std::vector< pair<int, int> >& nums) {
		for (auto num : nums) {
			cout << num.first << ", " << num.second << endl;
		}
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
	Solution s;
	std::vector<int> nums1 = {1,7,11};
	std::vector<int> nums2 = {2,4,6};
	std::vector< std::vector<int> > res = s.kSmallestPair(nums1, nums2, 3);
	s.showVec(res);
	return 0;
}
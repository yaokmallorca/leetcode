#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int subarraySum1(std::vector<int>& nums, int k) {
		int res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			/* code */
			int cur_sum = nums[i];
			if (cur_sum == k) ++res;
			for (int j = i+1; j<nums.size(); ++j) {
				cur_sum += nums[j];
				if (cur_sum == k) ++res;
			}
		}
		return res;
	}

	int subarraySum(std::vector<int>& nums, int k) {
		int res = 0, sum = 0, n = nums.size();
		unordered_map<int, int> m{{0, 1}};
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			cout << "sum: " << sum << ", " << m[sum-k] << endl;
			res += m[sum - k];
			++m[sum]; 
			showMap(m);
			cout << "<<<<<<<<<<<<<<<<<<" << endl;
		}
		return res;
	}

	void showMap(unordered_map<int, int>& umap) {
		for (auto item : umap) {
			cout << item.first << " " << item.second << endl;
		}
	}

};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {1,2,3};
	Solution s;

	cout << s.subarraySum(nums, 3) << endl;

	return 0;
}
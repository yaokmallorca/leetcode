#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	bool containsDuplicate(std::vector<int> nums) {
		unordered_map<int, int> umap;
		for (int i = 0; i < nums.size(); ++i) {
			/* code */
			umap[nums[i]] += 1;
			if (umap[nums[i]] > 1) {
				return true;
			}
		}
		return false;
	}

	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		unordered_map<long long, int> umap;
		int j = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (i - j > k) m.erase(nums[j++]);
			auto a = m.lower_bound((long long)nums[i] - t);
			if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
			m[nums[i]] = i;
		}
		return false;
	}

	bool containsDuplicateII(std::vector<int>& nums, int k) {
		unordered_map<int, int> umap;
		for (int i = 0; i < nums.size(); ++i) {
			/* code */
			if (umap.find(nums[i]) != umap.end() && abs(i - umap[nums[i]]) <= k) return true;
			else umap[nums[i]] = i;
		}
		return false;
	}

	void showUMap(unordered_map<int, int> umap) {
		for (auto item : umap) {
			cout << item.first << ", " << item.second << endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {1,2,3,1,2,3};
	Solution s;
	bool res = s.containsDuplicateII(nums, 2);
	cout << "res: " << res << endl;


	std::vector<int> nums1 = {1,2,3,1}; // {1,5,9,1,5,9};
	int t=0, k=3;
	bool res2 = s.containsNearbyAlmostDuplicate(nums1, k, t);
	cout << "res1: " << res2 << endl; 
	return 0;
}
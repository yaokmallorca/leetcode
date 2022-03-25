#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int longestConsecutive1(std::vector<int>& nums) {
		if (nums.empty()) return 0;
		unordered_map<int, int> umap;
		int res = 0;

		for (auto num : nums) {
			/* code */
			if (umap.count(num)) continue;
			int left = umap.count(num-1) ? umap[num - 1] : 0;
			int right = umap.count(num+1) ? umap[num + 1] : 0;
			int sum = right + left + 1;
			umap[num] = sum;
			res = max(res, sum);
			umap[num - left] = sum;
			umap[num + right] = sum;
			cout << "l: " << left << ", r: " << right << ", s: " << sum << endl;
			showMap(umap);
			cout << "<<<<<<<<<<<<<<<<<<" << endl;
		}
		return res;
	}

	int longestConsecutive1(std::vector<int>& nums) {
		if (nums.empty()) return 0;
		// unordered_set<int> nums(nums.begin(), nums.end());
		int res=0;
		for (int i=0; i<nums.size(); ++i) {
			int l = i, r = i;
			int tmp = nums[i];
			nums.erase(nums.begin()+i);
			while(count(nums.begin(), nums.end(), tmp+1) && r < nums.size()) {
				++r; ++tmp;

			}
			tmp = nums[i];
			while(count(nums.begin(), nums.end(), tmp-1) && l > 0) {
				--l; --tmp;
			}
			res = max(res, r - l + 1);
			cout << "l: " << l << ", r: " << r << ", res: " << res << endl;
		}
		return res;
	}


	int longestConsecutive2(std::vector<int>& nums) {
		int res = 0;
		unordered_set<int> s(nums.begin(), nums.end());
		cout << "set: ";
		showSet(s);
		for (int val : nums) {
			if (!s.count(val)) continue;
			s.erase(val);
			int pre = val - 1, next = val + 1;
			while (s.count(pre)) s.erase(pre--);
			while (s.count(next)) s.erase(next++);
			res = max(res, next - pre - 1);
			cout << "set: ";
			showSet(s);
			cout << "<<<<<<<<<<<<<<<<<<<<<<" << endl;
		}
		return res;
	}

	void showSet(unordered_set<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}


	void showMap(unordered_map<int, int> umap) {
		for (auto m : umap) {
			cout << m.first << ", " << m.second << endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {100,4,200,1,3,2}; // {0,3,7,2,5,8,4,6,0,1};
	// {100,4,200,1,3,2};
	Solution s;
	cout << s.longestConsecutive(nums) << endl;
	return 0;
}
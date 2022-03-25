#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<int> > combinationSum(std::vector<int>& candidates,  int target) {
		std::vector< std::vector<int> > res;
		std::vector<int> result;
		int cur_sum = 0, level = 0;
		sort(candidates.begin(), candidates.end());
		combinationDFS(res, result, candidates, target, level);
		return res;
	}

	void combinationDFS(std::vector< std::vector<int> >& res, std::vector<int>& result, 
		std::vector<int> nums, int target, int level) {
		if (target == 0) {res.push_back(result); return;}
		if (target < 0) {return;}
		for (int i = level; i < nums.size(); ++i) {  // i = level
			/* code */
			if (i > level && nums[i] == nums[i - 1]) continue;
			result.push_back(nums[i]);
			combinationDFS(res, result, nums, target-nums[i], i+1); // level = i+1 所有元素只用一次
			result.pop_back();
		}
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
};

int main(int argc, char const *argv[])
{
	std::vector<int> candidates = {10,1,2,7,6,1,5};
	int target = 8;
	Solution s;
	s.showVec(candidates);
	cout << "<<<<<<<<<<<<<<<" << endl;
	std::vector< std::vector<int> > res = s.combinationSum(candidates, target);
	s.showVec(res);
	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<int> > combinationSum(std::vector<int>& candidates,  int target) {
		std::vector< std::vector<int> > res;
		std::vector<int> result;
		int cur_sum = 0, level = 0;
		combinationDFS(res, result, candidates, target, cur_sum, level);
		return res;
	}

	void combinationDFS(std::vector< std::vector<int> >& res, std::vector<int>& result, 
		std::vector<int> nums, int target, int cur_sum, int level) {
		if (cur_sum == target) {res.push_back(result); return;}
		if (cur_sum > target) {cur_sum = 0; return;}
		// for (auto num : nums) {
		// for (int i = 0; i < nums.size(); ++i) { // 包含重复组合
		for (int i = level; i < nums.size(); ++i) { // 不包含重复
			/* code */
			cur_sum += nums[i];
			result.push_back(nums[i]);
			combinationDFS(res, result, nums, target, cur_sum, i);
			cur_sum -= nums[i];
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

int main(int argc, char const *argv[]) {
	std::vector<int> candidates = {2,3,5};
	Solution s;
	std::vector< std::vector<int> > res = s.combinationSum(candidates, 8);
	s.showVec(res);

	return 0;
}
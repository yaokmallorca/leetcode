#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<int> > permute(std::vector<int>& nums) {
		std::vector< std::vector<int> > results;
		std::vector<int> result; 
		permuteDFS(results, nums, result);
		return results;
	}

	void permuteDFS(std::vector< std::vector<int> >& results, std::vector<int>& nums, 
		std::vector<int>& result) {
		if (result.size() == nums.size()) {results.push_back(result); return;}
		for (int i = 0; i<nums.size(); ++i) {
			if (count(result.begin(), result.end(), nums[i]))
				continue;
			result.push_back(nums[i]);
			permuteDFS(results, nums, result);
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
	std::vector<int> nums = {1, 2, 3};
	Solution s;
	std::vector< std::vector<int> > res = s.permute(nums);
	s.showVec(res);
	return 0;
}
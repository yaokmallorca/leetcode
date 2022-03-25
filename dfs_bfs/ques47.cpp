#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<int> > permuteUnique(std::vector<int>& nums) {
		int n = nums.size();
		std::vector< std::vector<int> > results;
		std::vector<int> result;
		std::vector<int> visited(n, 0);
		sort(nums.begin(), nums.end());
		// permuteDFS(results, result, visited, nums, 0);
		permuteDFS(nums, 0, visited, result, results);
		return results;
	}

	//void permuteDFS(std::vector< std::vector<int> >& results, 
	//	vector<int>& result, std::vector<bool>& visited, 
	//	std::vector<int> nums, int level) {
	//	if (level >= nums.size()) {
	//		results.push_back(result);
	//		return;
	//	}
	//	for (int i = 0; i < nums.size(); ++i) {
	//		/* code */
	//		if (visited[i]) continue;
	//		if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
	//		result.push_back(nums[i]);
	//		visited[i] = true;
	//		permuteDFS(results, result, visited, nums, level+1);
	//		result.pop_back();
	//		visited[i] = false;
	//	}
	//}

	void permuteDFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
		if (level >= nums.size()) {res.push_back(out); return;}
		for (int i = 0; i < nums.size(); ++i) {
			if (visited[i] == 1) continue;
			if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
			visited[i] = 1;
			out.push_back(nums[i]);
			permuteDFS(nums, level + 1, visited, out, res);
			out.pop_back();
			visited[i] = 0;
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
	void showSet(std::unordered_set< std::vector<T> > nums) {
		for (auto num : nums) {
			showVec(num);
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
	/* code */
	std::vector<int> nums = {3,3,0,3};
	Solution s;
	std::vector< std::vector<int> > res = s.permuteUnique(nums);
	s.showVec(res);
	return 0;
}
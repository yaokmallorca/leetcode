#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<int> > subsets_dfs(std::vector<int>& nums) {
		std::vector< std::vector<int> > res;
		std::vector<int> out;
		res.push_back({});
		subsetDFS(nums, res, out, 0);
		return res;
	}

	void subsetDFS(std::vector<int> nums, std::vector< std::vector<int> >& res, std::vector<int>& out, int start) {
		res.push_back(out);
		for (int i = start; i < nums.size(); ++i) {
			/* code */
			out.push_back(nums[i]);
			subsetDFS(nums, res, out, i+1);
			out.pop_back();
		}
	}

	std::vector< std::vector<int> > subsets(std::vector<int>& nums){
		std::vector< std::vector<int> > res;
		res.push_back({});
		for (int i = 0; i < nums.size(); ++i) {
			/* code */
			int n = res.size();
			std::vector<int> tmp;
			for (int j=0; j<n; ++j) {
				tmp = res[j];
				tmp.push_back(nums[i]);
				res.push_back(tmp);
			}
		}
		return res;

	}


	template<typename T>
	void showVec(std::vector<T>& nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	template<typename T> 
	void showVec(std::vector< std::vector<T> >& nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {1,2,3};
	Solution s;
	std::vector< std::vector<int> > res = s.subsets(nums);
	s.showVec(res);

	return 0;
}
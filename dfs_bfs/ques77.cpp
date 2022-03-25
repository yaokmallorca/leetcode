#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<int> > combine(int n, int k) {
		int level = 1;
		std::vector< std::vector<int> > res;
		std::vector<int> nums;

		combineDFS(res, level, n, k, nums); 
		return res;
	}

	void combineDFS(std::vector< std::vector<int> >& res, int level, int n, int k, std::vector<int>& nums) {
		if (nums.size() == k) {res.push_back(nums); return;}
		for (int i = level; i <= n; ++i) {
			/* code */
			nums.push_back(i);
			combineDFS(res, i+1, n, k, nums);
			nums.pop_back();
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
	Solution s;
	int n = 4, k = 2;
	std::vector< std::vector<int> > res = s.combine(n, k);
	s.showVec(res);
	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<int> > combinationSum(int k, int n) {
		std::vector< std::vector<int> > res;
		std::vector<int> result;
		combinationDFS(res, result, k, n, 1, 0);
		return res;
	}
	

	void combinationDFS(std::vector< std::vector<int> >& res, std::vector<int>& result,
		int k, int n, int start, int cur_sum) {
		if (cur_sum > n) return;
		if (cur_sum == n && result.size() == k) {res.push_back(result); return;}
		// if (n < 0) return;
		for (int i = start; i <= 9; ++i) { // i = start
			/* code */
			result.push_back(i);
			combinationDFS(res, result, k, n, i+1, cur_sum+i); // level = i+1, 每个元素用一次
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
	Solution s;
	int k = 9, n = 45;
	std::vector< std::vector<int> > res = s.combinationSum(k, n);
	s.showVec(res);
	return 0;
}
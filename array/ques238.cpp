#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	std::vector<int> productExceptSelf1(std::vector<int>& nums) {
		if (nums.empty()) return {};
		int n = nums.size();
		std::vector<int> fw(n, 1), bw(n, 1), res(n, 1);

		for (int i = 0; i < n - 1; ++i) {
			fw[i + 1] = fw[i] * nums[i];
		}
		cout << "fw: ";
		showVec(fw);
		for (int i = n - 1; i > 0; --i) {
			bw[i - 1] = bw[i] * nums[i];
		}
		cout << "bw: ";
		showVec(bw);
		for (int i = 0; i < n; ++i) {
			res[i] = fw[i] * bw[i];
		}
		return res;
	}

	std::vector<int> productExceptSelf(std::vector<int>& nums) {
		int n = nums.size(), temp = 1;
		std::vector<int> res(n, 1);
		for (int i = 0; i < n - 1; ++i) {
			res[i + 1] = res[i] * nums[i];
		}

		for (int i = n - 1; i > 0; --i) {
			temp = temp * nums[i];
			res[i-1] = res[i] * temp;
		}
		return res;

	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
 		}
 		cout << endl;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {1,2,3,4};
	Solution s;
	s.showVec(nums);
	std::vector<int> res = s.productExceptSelf(nums);
	s.showVec(res);
	return 0;
}
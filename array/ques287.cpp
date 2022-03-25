#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int findDuplicate(std::vector<int>& nums) {
		unordered_map<int, int> umap;
		for (int i = 0; i < nums.size(); ++i) {
			/* code */
			if (umap[nums[i]] == 1) return nums[i];
			umap[nums[i]] = 1;
		}
		return 0;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {3,1,3,4,2};
	Solution s;
	cout << s.findDuplicate(nums) << endl;

	return 0;
}
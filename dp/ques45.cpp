#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int jump(std::vector<int> nums) {
		int step = 0, cur = 0, last = 0, n = nums.size();
		for (int i = 0; i < n; ++i) {
			/* code */
			cur = max(i + nums[i], cur);
			if (i == last) {
				last = cur;
				++step;
				if (cur >= n-1) break;
			}
		}
		return res;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {2,3,1,1,4};
	Solution s;
	cout << s.jump(nums) << endl;
	return 0;
}
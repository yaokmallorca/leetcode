#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int search(std::vector<int> nums, int target) {
		
		int left = 0, right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		return -1;

	}
	
};

int main(int argc, char const *argv[]) {
	/* code */
	std::vector<int> nums = {-1,0,3,5,9,12};
	Solution s;
	int result = s.search(nums, 9);
	cout << "result: " << result << endl;

	return 0;
}
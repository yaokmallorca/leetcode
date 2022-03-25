#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

	// 二分法 
	int search1(std::vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			// which side is sorted
			if (nums[mid] == target) return mid;
			if (nums[mid] < nums[right]) {// right side is sorted
				if (target <= nums[right] && target > nums[mid]) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			} else {
			 // (nums[mid] > nums[left]) { // left side is sorted
				if (target < nums[mid] && target > nums[left]) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			}
		}
		return 0;
	}

	int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
	}
	
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> nums = {1};
	cout << s.search(nums, 1) << endl;
	return 0;
}
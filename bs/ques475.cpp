#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		int res = 0, n=heaters.size();
		sort(heaters.begin(), heaters.end());
		for(auto house : houses) {
			int first_higher_index = binarySearch(heaters, house);
			int last_lower_index = first_higher_index - 1;

			int dist1 = (first_higher_index == n) ? INT_MAX : heaters[first_higher_index] - house;
			int dist2 = (last_lower_index == 0) ? INT_MAX : house - heaters[last_lower_index];
			res = max(res, min(dist1, dist2));
		}
		return res;
	}
	
	// the first highest than target
	int binarySearch(std::vector<int> nums, int target) {
		int left = 0, right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (target < nums[mid]) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		return right;
	}

};

int main(int argc, char const *argv[]) {
	std::vector<int> houses = {1,2,3}; // {1,2,3,4};
	std::vector<int> heaters = {2}; // {1,4};

	Solution s;
	int min_r = s.findRadius(houses, heaters);
	cout << min_r << endl;

	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int missingElement_slow(std::vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		unordered_map<int, int> hmap;
		int cnt = 1, extend_num = k - (nums[len-1] - k) + nums[len-1] + 1;
		int max_num = nums[len-1]+1 > extend_num ? nums[len-1]+1 : extend_num;

		for (int i = nums[0]; i < max_num; ++i) {
			/* code */
			if (0 == count(nums.begin(), nums.end(), i)) {
				hmap[cnt++] = i;
			}
		}
		// show_map(hmap);
		return hmap[k];
	}

	void show_map(unordered_map<int, int> hmap) {
		for (const auto& [key, value] : hmap) {
			cout << "key: " << key << ", value: " << value << endl;
		}
	}

	int missingElement(std::vector<int>& nums, int k) {
		int len = nums.size();
		for (int i = 1; i < len; i++) {
			int loss = nums[i] - nums[i - 1] - 1;
			if (loss >= k) { // the miss is between nums[i] and nums[i-1]
				return nums[i - 1] + k;
			} else {
				k = k - loss;
			}
		}
		return nums[len - 1] + k;
	}

};

int main() {
	// std::vector<int> nums = {4,7,9,10};
	std::vector<int> nums = {1,2,4};
	Solution s;

	int result = s.missingElement(nums, 3);
	cout << "result: " << result << endl;

}


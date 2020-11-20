#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if(nums.empty()) return 0;
		std::vector<int>::iterator iter = nums.begin()+1;
		int prev = nums[0];
		if ( target <= prev )
			return 0;
		int pos = 1;
		while (iter != nums.end() ) {
			if (*iter == target){
				return pos;
			}
			if (target>prev && target<*iter) {
				return pos;
			}
			iter ++;
			pos ++;
		}
		return pos;
	}
};

int main() {
	int data[4] = {1,3,5,6};
	int val = 2;
	vector<int> nums;

	for (int i=0; i<4; i++) {
		nums.push_back(data[i]);
	}

	Solution s;
	int ret = s.searchInsert(nums, val);
	cout << "result: " << ret << endl;
	return 0;
}
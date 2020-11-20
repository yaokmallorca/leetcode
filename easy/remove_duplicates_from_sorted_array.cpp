#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int tmp = nums[0];
		std::vector<int>::iterator i = nums.begin()+1;
		while( i != nums.end() ) {
			if ( tmp == *i ){
				tmp = *i;
				nums.erase(i);
			} else {
				// cout << tmp << ", " << *i << endl;
				tmp = *i;
				i++;
			}
		}
		return nums.size();
	}
};


int main() {
	vector<int> nums;
	int data[18] = {0,0,1,1,1,2,2,3,3,4,5,5,7,7,8,8,9,9};
	for (int i=0; i<18; i++) {
		nums.push_back(data[i]);
	}

	Solution s;
	int ret = s.removeDuplicates(nums);
	cout << ret << endl;
	return 0;
}
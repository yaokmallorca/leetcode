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
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()) return 0;
		std::vector<int>::iterator i = nums.begin();
		while( i != nums.end() ) {
			if ( val == *i ){
				nums.erase(i);
				continue;
			} 
			i++;
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
	int ret = s.removeElement(nums, 7);
	cout << ret << endl;
	return 0;
}
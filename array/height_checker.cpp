#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:

	int heightChecker(vector<int>& heights) {
		if (heights.size()==0) {return 0;}
		vector<int> unsortedHeights(heights);
		int ret = 0;
		sort(heights.begin(), heights.end());
		for (int i=0; i<heights.size(); i++) {
			if (heights[i] != unsortedHeights[i]) {
				ret += 1;
			}
		}
		return ret;
	}

	void showVec(vector<int>& nums) {
		for (int num : nums) {
			cout << num << ", "; 
		}
		cout << endl;
	}

	int thirdMax_set(vector<int>& nums) {
		set<int> tmp;
		for (int num : nums) {
			tmp.insert(num);
			if (tmp.size() > 3) {
				tmp.erase(tmp.begin());
			} 
		}
		return tmp.size() == 3 ? *tmp.begin() : *tmp.rbegin();
	}

	int thirdMax(vector<int>& nums) {
		long firstmax = LONG_MIN, secondmax = LONG_MIN, thirdmax = LONG_MIN;
		int n = nums.size();
		for (int i=0; i<n; i++) {
			if (nums[i] > firstmax) {
				thirdmax = secondmax;
				secondmax = firstmax;
				firstmax = nums[i];
			}else if (nums[i] > secondmax && nums[i] < firstmax) {
				thirdmax = secondmax;
				secondmax = nums[i];
			}else if (nums[i] > thirdmax && nums[i] < secondmax) {
				thirdmax = nums[i];
			}
		}
		return (thirdmax == LONG_MIN || thirdmax == secondmax) ? firstmax : thirdmax;
	}

	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> ret;
		for (int i=0; i<nums.size(); i++) {
			int idx = abs(nums[i]) - 1;
			nums[idx] = (nums[idx]>0) ? -nums[idx] : nums[idx];
		}
		for (int i=0; i<nums.size(); i++) {
			if (nums[i] > 0) {
				ret.push_back(i+1);
			}
		}
		return ret;
	}

	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ret;
		for (int i=0; i<nums.size(); i++) {
			int idx = abs(nums[i]) - 1;
			if(nums[idx] < 0) {ret.push_back(idx+1);}
			nums[idx] = -nums[idx];
		}
		return ret;
	}

};


int main() {
	vector<int> height = {1,1,4,2,1,3};
	Solution s;
	int move_students = s.heightChecker(height);
	cout << "minimus students need to move: " << move_students << endl;

	vector<int> arr = {2, 2, 3, 1};
	int thirdmax = s.thirdMax(arr);
	cout << "third max: " << thirdmax << endl;

	vector<int> find_arr = {4,3,2,7,8,2,3,1};
	vector<int> find_result = s.findDisappearedNumbers(find_arr);
	s.showVec(find_result);

	vector<int> find_dup = {4,3,2,7,8,2,3,1};
	vector<int> find_dup_result = s.findDuplicates(find_dup);
	s.showVec(find_dup_result);
}
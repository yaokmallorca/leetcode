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
	vector< vector<int> > threeSum1(vector<int>& nums) {
		int N = nums.size();
		if (N<=2) {return {};}
		sort(nums.begin(), nums.end());

		vector< vector<int> > ret;
		set< pair<int, int> > tmp;
		int target = 0;
		// int i=0, j=nums.size()-1;
		for(int i=0; i<N; i++) {
			int sub0 = target - nums[i];
			for(int j=i+1; j<N; j++){
				int sub1 = sub0 - nums[j];
				for(int z=j+1; z<N; z++) {
					if((nums[z] == sub1) && (tmp.count(make_pair(nums[j], nums[z]))==0)){
						ret.push_back({nums[i], nums[j], nums[z]});
						tmp.insert(make_pair(nums[j], nums[z]));
					}
				}
			}
		}
		return ret;
	}

	vector< vector<int> > threeSum(vector<int>& nums) {
		int N = nums.size();
		if (N<=2) {return {};}
		sort(nums.begin(), nums.end());
		vector< vector<int> > res;
		set< pair<int, int> > tmp;

		for (int i=0; i<N; i++) {
			if (nums[i] > 0) break;
			int target = 0 - nums[i], j = i+1, k = N-1;
			while ( j<k ) {
				if (nums[j] + nums[k] == target && tmp.count( make_pair(nums[j], nums[k])) == 0 ) {
					res.push_back({nums[i], nums[j], nums[k]});
					tmp.insert(make_pair(nums[j], nums[k]));
					j++; k--;
				} else if (nums[j] + nums[k] < target) {
					j++;
				} else {
					k--;
				}
			}
		}
		return res;
	}

	int threeSumClosest(vector<int>& nums, int target) {
		int N = nums.size();
		if (N<=1) return 0;
		sort(nums.begin(), nums.end());
		int diff = INT_MAX;
		int ret = 0;

		for (int i=0; i<N; i++) {
			int j = i+1, k = N-1;
			while ( j<k ) {
				int sum = nums[i] + nums[j] + nums[k];
				int new_diff = abs(target - sum);
				if (new_diff < diff){
					diff = new_diff;
					ret = sum;
					// cout << nums[i] << ", " << nums[j] << ", " << nums[k] << endl;
				} 
				if (sum < target) j++;
				else k--;
			}
		}
		return ret;
	}

	void showset(set<pair<int, int> > a){
		set<pair<int, int> >::iterator iter = a.begin();
		while (iter != a.end()) {
			cout << iter->first << ", " << iter->second << endl;
			iter ++;
		}
	}

	vector< vector<int> > fourSum(vector<int>& nums, int target) {
		int N = nums.size();
		if (N <= 3) {return vector< vector<int> >({});}
		sort(nums.begin(), nums.end());
		set< vector<int> > res;

		for (int i=0; i<N; i++) {
			for (int j=i+1; j<N; j++) { // j<(N-3)
				int left = j+1, right = N-1;
				while (left < right) {
					int sum = nums[i]+nums[j]+nums[left]+nums[right];
					if (sum == target) {
						vector<int> four_nums({nums[i], nums[j], nums[left], nums[right]});
						res.insert(four_nums);
						left++; right--;
					} else if (sum < target) {
						left++;
					} else {
						right--;
					}
				}
			}
		}
		return vector< vector<int> >(res.begin(), res.end());
	}

};

int main() {
	int a[9] = {-1, 0, 1, 2, -1, -4, -1, 2, -1};
	vector<int> height;
	for(int i=0; i<9; i++) {
		height.push_back(a[i]);
	}
	Solution s;

	vector< vector<int> > result = s.threeSum(height);
	for(vector< vector<int> >::iterator iter0 = result.begin(); iter0 != result.end(); iter0++) {
		vector<int> sub_vec = *iter0;
		for( vector<int>::iterator iter1 = sub_vec.begin(); iter1 != sub_vec.end(); iter1++) {
			cout << *iter1 << " ";
		}
		cout << endl;
	}
	
	cout << "############################" << endl;
	// int b[5] = {1,1,-1,-1,3};
	int b[4] = {-1, 2, 1, -4};
	vector<int> arr;
	for(int i=0; i<4; i++) {
		arr.push_back(b[i]);
	}
	int target = 1;
	int closest = s.threeSumClosest(arr, target);
	cout << "closest: " << closest << endl;

	cout << "############################" << endl;
	// int b[5] = {1,1,-1,-1,3};
	int c[6] = {1, 0, -1, 0, -2, 2};
	vector<int> arr1;
	for(int i=0; i<6; i++) {
		arr1.push_back(c[i]);
	}
	target = 0;
	vector< vector<int> > result1 = s.fourSum(arr1, target);
	cout << "result: " << endl;
	for(vector< vector<int> >::iterator iter0 = result1.begin(); iter0 != result1.end(); iter0++) {
		vector<int> sub_vec = *iter0;
		for( vector<int>::iterator iter1 = sub_vec.begin(); iter1 != sub_vec.end(); iter1++) {
			cout << *iter1 << " ";
		}
		cout << endl;
	}

	cout << "############################" << endl;
	// int b[5] = {1,1,-1,-1,3};
	int d[4] = {0, 0, 0, 0};
	vector<int> arr2;
	for(int i=0; i<4; i++) {
		arr2.push_back(d[i]);
	}
	vector< vector<int> > result2 = s.fourSum(arr2, target);
	cout << "result: " << endl;
	for(vector< vector<int> >::iterator iter0 = result2.begin(); iter0 != result2.end(); iter0++) {
		vector<int> sub_vec = *iter0;
		for( vector<int>::iterator iter1 = sub_vec.begin(); iter1 != sub_vec.end(); iter1++) {
			cout << *iter1 << " ";
		}
		cout << endl;
	}

	return 0;
}
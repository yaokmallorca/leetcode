#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
	int maxArea1(vector<int>& height) {
		int N = height.size();
		if (N<=1) {return 0;}
		if (N==2) {return height[0]<height[1] ? height[0] : height[1];}
		int max0=height[0], max1=height[0];
		int ind_max0=0, ind_max1=0, sec = 0;
		for(int i=0; i<N; i++) {
			if(height[i] > max0){
				max0 = height[i];
				ind_max0 = i;
			}
			if(height[i] > max1 && (i > ind_max0)){ // && (height[i]<=max0) 
				max1 = height[i];
				ind_max1 = i;
			}
			sec = max0;
		}
		cout << ind_max0 << ", " << max0 << ", " << ind_max1 << ", " << max1 << endl;
		int tempind = 0, tempval = 0;
		if (ind_max0 > ind_max1) {
			tempind = ind_max0;
			ind_max0 = ind_max1;
			ind_max1 = tempind;
			tempval = max0;
			max0 = max1;
			max1 = tempval;
		}
		cout << ind_max0 << ", " << max0 << ", " << ind_max1 << ", " << max1 << endl;
		int max_size = (ind_max1 - ind_max0) * (max0<max1 ? max0 : max1);
		cout << "max size: " << max_size << endl;
		for(int i=0; i<ind_max0; i++) {
			int tmp = (ind_max1 - i) * (height[i]<max1 ? height[i] : max1);
			if (tmp > max_size) {
				max_size = tmp;
				ind_max0 = i;
				max0 = height[i];
			}
		}
		for(int i=ind_max1; i<N; i++) {
			int tmp = (i - ind_max0) * (height[i]<max0 ? height[i] : max0);
			if (tmp > max_size) {
				max_size = tmp;
				ind_max1 = i;
				max1 = height[i];
			}
		}
		cout << ind_max0 << ", " << max0 << ", " << ind_max1 << ", " << max1 << endl;
		return max_size;
	}

	int maxArea(vector<int>& height) {
		int res = 0, i = 0, j = height.size() - 1;
		while (i < j) {
			int h = min(height[i], height[j]);
			res = max(res, h * (j - i));
			while (i < j && h == height[i]) ++i;
			while (i < j && h == height[j]) --j;
		}
		return res;
	}
};


int main() {
	int a[9] = {1,8,6,2,5,4,8,3,7};
	vector<int> height;
	for(int i=0; i<9; i++) {
		height.push_back(a[i]);
	}
	Solution s;
	int size = 0;
	size = s.maxArea(height);
	cout << "result: " << size << endl;
	height.clear();
	cout << "################" << endl;

	int b[9] = {1,8,6,2,5,4,8,25,7};
	for(int i=0; i<9; i++) {
		height.push_back(b[i]);
	}
	size = 0;
	size = s.maxArea(height);
	cout << "result: " << size << endl;
	height.clear();
	cout << "################" << endl;
	
	int c[11] = {1,2,3,4,5,6,7,8,9,10};
	for(int i=0; i<11; i++) {
		height.push_back(c[i]);
	}
	size = 0;
	size = s.maxArea(height);
	cout << "result: " << size << endl;
	height.clear();
	cout << "################" << endl;
	/*
	int d[3] = {1,2,1};
	for(int i=0; i<3; i++) {
		height.push_back(d[i]);
	}
	size = 0;
	size = s.maxArea(height);
	cout << "result: " << size << endl;
	height.clear();
	cout << "################" << endl;
	*/
	return 0;
}
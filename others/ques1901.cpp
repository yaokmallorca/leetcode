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
	int get_index(vector<int>& a, int& value) {
		int max_value = INT_MIN;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == value) {
				return i;
			}
		}
		return 0;
	}

	int get_max(vector<int>& a) {
		int max_value = INT_MIN;
		for (int i = 0; i < a.size(); i++) {
			max_value = max(max_value, a[i]);
		}
		return max_value;
	}

	std::vector<int> findPeakGrid(std::vector< std::vector<int> >& mat) {
	int left = 0, right = mat.size() - 1;
	vector<int> res;
	while (left <= right) {
		int mid = (left + right) / 2;
		int max_up = 0;
		int max_mid = 0;
		int max_down = 0;
	   
		if ((mid - 1) >= 0 && (mid - 1) < mat.size()) {
			max_up = get_max(mat[mid- 1]);
		}
		if (mid >= 0 && mid < mat.size()) {
			max_mid = get_max(mat[mid]);
		}
		if ((mid + 1) >= 0 && (mid + 1) < mat.size()) {
			max_down = get_max(mat[mid + 1]);
		}
		// == 是用来解case的
		// 当up和mid相等情况下，>是无结果的； 同时相邻的数字是不同等的，故使用==可解case
		if (max_mid >= max_up && max_mid >= max_down) {
			res.push_back(mid);
			res.push_back(get_index(mat[mid], max_mid));
			return res;
		} else if (max_up > max_mid && max_up > max_down) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return res;
	}

};
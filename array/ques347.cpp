#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:

	// nlog(n)
	vector<int> topKFrequent(vector<int>& nums, int k) {
		int n = nums.size();
		std::vector<int> dp(n, 0);
		for (int i = 0; i < n; ++i) {
			/* code */
			++dp[nums[i]];
		}
		showVec(dp);
		mergeSort(dp, 0, dp.size()-1);
		showVec(dp);
		return dp;

	}

	void merge(std::vector<int> &list, int lo, int mi, int hi) {
		// Make a copy of the list
		std::vector<int> *originalList = deepCopy(list);
		int i = lo;
		int j = mi + 1;
		
		// Iterate through the list
		for (int k = lo; k <= hi; k++) {
			if (i <= mi and (j > hi or (*originalList)[i] < (*originalList)[j])) {
				list[k] = (*originalList)[i];
				i++;
			} else {
				list[k] = (*originalList)[j];		 
				j++;
			}
		} 
		delete originalList;
	}

	std::vector<int> *deepCopy(std::vector<int> &list) {
		std::vector<int> *newList = new std::vector<int>(list.size());
		for (unsigned int i = 0; i < list.size(); i++) {
			(*newList)[i] = list[i];
		}
		return newList;
	}

	void mergeArray(std::vector<int>& nums, int left, int mid, int right) {
		std::vector<int> tmp(right - left + 1, 0);
		int pos = 0, l_pos = left, r_pos = mid + 1;
		while (l_pos <= mid && r_pos <= right) {
			if (nums[l_pos] > nums[r_pos]) {
				tmp[pos++] = nums[l_pos++];
			} else {
				tmp[pos++] = nums[r_pos++];
			}
		}
		while(l_pos <= mid) tmp[pos++] = nums[l_pos++];
		while(r_pos <= right) tmp[pos++] = nums[r_pos++];
		for (int i = 0; i < tmp.size(); ++i) {
			/* code */
			nums[left + i] = tmp[i];
		}
	}

	void mergeSort(std::vector<int>& nums, int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			mergeSort(nums, left, mid);
			mergeSort(nums, mid+1, right);
			// merge(nums, left, mid, right);
			mergeArray(nums, left, mid, right);
		}
	}


	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	void showMap(priority_queue< pair<int, int> >& pmap) {
		while(!pmap.empty()){
			auto it=pmap.top();
			pmap.pop();
			cout << it.first << " " << it.second << endl;
		}

	}

	void showMap(unordered_map<int, int> umap) {
		for (auto it : umap) {
			cout << it.first << " " << it.second << endl;
		}
	}


	void queTest(std::vector<int>& nums) {
		unordered_map<int, int> umap;
		priority_queue< pair<int, int> > pmap;

		for (int i = 0; i < nums.size(); ++i) {
			/* code */
			++umap[nums[i]];
		}
		showMap(umap);
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		for (auto it : umap) {
			pmap.push({it.second, it.first});
		}
		showMap(pmap);
	}

};


int main(int argc, char const *argv[])
{
	/* code */
	std::vector<int> nums = {1,1,1,2,2,3};
	Solution s;
	std::vector<int> res = s.topKFrequent(nums, 2);

	// std::vector<int> a = {3,4,6,6,8,9,10,1,1,1,2,2,2,3};
	// std::vector<int> a = {3,5,1,3,6,7,3,1,6,3,1,7,8,4,1};
	// std::vector<int> b = {-1,-2,0,0,1,-3,-5,7,2,1001,2000,4};
	// int left = 0, right = a.size() -1;
	// int mid = left + (right - left) / 2;
	// s.showVec(res);

	s.queTest(nums);
	return 0;
}

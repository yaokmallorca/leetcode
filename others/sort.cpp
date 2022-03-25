#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Sort
{
public:
	void mergeSort(std::vector<int>& nums, int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			mergeSort(nums, left, mid);
			mergeSort(nums, mid+1, right);
			merge(nums, left, mid, right);
		}
	}

	void selectSort(std::vector<int>& nums) {
		if (nums.size() <= 1) return;
		int n = nums.size();
		for (int i = 0; i < n; ++i){
			/* code */
			for (int j=i+1; j<n; ++j) {
				if (nums[i] > nums[j]) 
					swap(nums[i], nums[j]);
			}
		}
	}

	void bubbleSort(std::vector<int>& nums) {
		if (nums.size()<=1) return;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			/* code */
			for(int j=0; j < n-i-1; ++j) {
				if (nums[j+1] < nums[j]) 
					swap(nums[j+1], nums[j]);
			}
		}
	}

	void insertSort(std::vector<int>& nums) {
		if (nums.size() <= 1) return;
		int n = nums.size();
		for (int i = 1; i < n; ++i) {
			/* code */
			for (int j = i-1; j>=0 && nums[j+1]<nums[j] ; --j) {
				/* code */
				swap(nums[j+1], nums[j]);
			}

		}
	}

	void shellSort(std::vector<int>& nums) {
		if (nums.size() <= 1) return;
		int n = nums.size(), gap = n / 2, tmp = 0;
		while (gap > 0) {
			for (int i = gap; i < n; ++i) {
				/* code */
				tmp = nums[i];
				int pre_ind = i - gap;
				while (pre_ind >= 0 && nums[pre_ind] > tmp) {
					nums[pre_ind + gap] = nums[pre_ind];
					pre_ind -= gap;
				} 
				nums[pre_ind + gap] = tmp;
			}
			gap /= 2;
		}
	}


	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}


private:
	void merge(std::vector<int>& nums, int left, int mid, int right) {
		std::vector<int> tmp(right - left + 1, 0);
		int l_ind = left, r_ind = mid+1, pos = 0;

		while (l_ind <= mid && r_ind <= right) {
			if (nums[l_ind] < nums[r_ind]) {
				tmp[pos++] = nums[l_ind++];
			} else {
				tmp[pos++] = nums[r_ind++];
			}
		}
		while (l_ind <= mid) tmp[pos++] = nums[l_ind++];
		while (r_ind <= right) tmp[pos++] = nums[r_ind++];

		for (int i = 0; i < tmp.size(); ++i) {
			/* code */
			nums[left+i] = tmp[i];
		}
	}

};

int main(int argc, char const *argv[])
{
	std::vector<int> a = {1,0,-4,-7,9,6,21,6534,11,-1123,90};
	Sort s;
	s.showVec(a);
	// s.mergeSort(a, 0, a.size()-1);
	// s.bubbleSort(a);
	// s.insertSort(a);
	s.shellSort(a);
	s.showVec(a);
	return 0;
}
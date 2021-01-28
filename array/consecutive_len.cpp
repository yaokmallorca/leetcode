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
	int findMaxConsecutiveOnesBeginEnd(std::vector<int>& nums) {
		if (nums.size() <= 1) {return 0;}
		int N = nums.size();
		int len_begin = 0, len_end = 0;
		int prev_left = 0, curr_left = 0;
		int prev_right = 0, curr_right = 0;
		int len_left = 1, len_right = 1, longest_len = 0;
		bool left_end = false, right_end = false;
		for (int i=1; i<N/2; i++) {
			prev_left = nums[i-1];
			curr_left = nums[i];
			prev_right = nums[N-i];
			curr_right = nums[N-i-1];
			if (prev_left == curr_left) {
				len_left += 1;
			} else {
				if (longest_len < len_left) {
					longest_len = len_left;
				}
				len_left = 1;
				left_end = true;
			}
			if (prev_right == curr_right) {
				len_right += 1;
			} else {
				if (longest_len < len_right) {
					longest_len = len_right;
				}
				len_right = 1;
				right_end = true;
			}
			if(left_end == true && right_end == true)
				break;
		}
		return longest_len;
	}

	int findMaxConsecutiveOnes0(std::vector<int>& nums) {
		if (nums.size() == 1) {
			if(nums[0] == 1) {return 1;}
			else {return 0;}
		}
		int N = nums.size();
		int longest_len = 0, len = 0;
		int prev = 0, curr = 0;
		for (int i=1; i<N; i++) {
			prev = nums[i-1];
			curr = nums[i];
			if (curr == 1 && prev == 1) {
				if (len ==0){len = 2;}
				else {len += 1;}
			} else if (curr == 1) {
				len = 1;
			} else {
				if (len > longest_len) {
					longest_len = len;
				}
				len = 0;
			}
		}
		return longest_len < len ? len : longest_len;
	}

	int findMaxConsecutiveOnes(std::vector<int>& nums) {
		int res = 0, cnt = 0;
		for (int num : nums) {
			num == 1 ? cnt += 1 : cnt = 0;
			res = max(res, cnt);
		}
		return res;
	}

	int findNumbers(vector<int>& nums) {
		int ret = 0;
		for (int num : nums) {
			int cnt = countDigits(num);
			if (cnt % 2 == 0) {ret += 1;}
		}
		return ret;
	}

	int countDigits(int num) {
		int ret = 1;
		while (num / 10 != 0) {
			num = num / 10;
			ret += 1;
		}
		return ret;
	}

	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> res;
		for (int num : nums) {
			res.push_back(num*num);
		}
		cout << res.size() << endl;
		sort(res.begin(), res.end());
		return res;
	}

	void showVec(vector<int>& nums) {
		for (int num : nums) {
			cout << num << ", "; 
		}
		cout << endl;
	}

	void duplicateZeros(vector<int>& arr) {
		int N = arr.size();
		int index = 0;
		while (index < N) {
			if (arr[index] == 0) {
				int tmp_ind = N - 1;
				while (tmp_ind >= (index + 2) ){
					arr[tmp_ind] = arr[tmp_ind-1];
					tmp_ind--;
				}
				arr[index+1] = 0;
				index += 2;
			}
			else {
				index++;
			}
		}
	}

	vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int m_pos=0, n_pos=0, pos=0;
		vector<int> res;
		while (pos < (m + n)) {
			while(n_pos < n) {
				if (nums2[n_pos] < nums1[m_pos]) {
					res.push_back(nums2[n_pos]);
					pos += 1;
					n_pos+=1;
				} else {
					res.push_back(nums1[m_pos]);
					m_pos += 1;
					pos += 1;
					// short_pos = j;
					break;
				}
			}
			if(n_pos >= n && pos < (m + n)){
				res.push_back(nums1[m_pos]);
				m_pos += 1;
				pos += 1;
			}
		}
		return res;
	}


	bool checkIfExist(vector<int>& arr) {
		bool ret = false;
		int N = arr.size();
		for (int i=0; i<N; i++) {
			for (int j=i+1; j<N; j++) {
				if((arr[i] == 2*arr[j] || 2*arr[i] == arr[j]) && (arr[i]!=0)) {
					ret = true;
					return ret;
				}
			}
		}
		return ret;
	}

	bool validMountainArray(vector<int>& arr) {
		int N = arr.size();
		int i = 0, j = N - 1;
		while(arr[i]<arr[i+1] && i<N-1) i++;
		while(arr[j]<arr[j-1] && j>0) j--;
		cout << i << ", " << j << endl;
		return (i==j && i<N-1 && j>0);
	}

	int vecMax(vector<int>& arr, int start_pos) {
		int max = 0;
		int N = arr.size();
		for (int i = start_pos; i<N; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		return max;
	}

	vector<int> replaceElements(vector<int>& arr) {
		int N = arr.size();
		int ind = 1;
		vector<int> res;
		vector<int>::iterator it = arr.begin();
		while(it != arr.end()) {
			int tmp = vecMax(arr, ind);
			res.push_back(tmp);
			ind += 1;
			it++;
		}
		res[N-1] = -1;
		return res;
	}

	// 0,0,1,1,1,2,2,3,3,4
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) {return 0;}
		std::vector<int>::iterator it = nums.begin()+1;
		while(it != nums.end()) {
			if(*it == *(it-1)){
				nums.erase(it-1);
				continue;
			}
			it++;
		}
		return nums.size();
	}

	void moveZeroes(vector<int>& nums) {
		int left = 0, right = 0;
		while (right < nums.size()) {
			if (nums[right]) {
				swap(nums[left], nums[right]);
				left += 1;
			}
			right++;
		}
	}
	
	vector<int> sortArrayByParity(vector<int>& nums) {
		if (nums.size() <= 1) {return nums;}
		for (int i=0, j=0; j<nums.size(); j++) {
			if (nums[j]%2 == 0) swap(nums[i++], nums[j]);
		}
		return nums;
	}

	std::vector<int> sortArrayByParityII(vector<int>& nums) {
		if (nums.size() <= 1) {return nums;}
		int n = nums.size(), odd_ind = 1, even_ind = 0;
		while (odd_ind < n && even_ind < n) {
			if (nums[even_ind] % 2 == 0) even_ind += 2;
			else if (nums[odd_ind] % 2 == 1) odd_ind += 2;
			else swap(nums[even_ind], nums[odd_ind]);
		}
		return nums;
	}

};

int main() {
	int a[2] = {1,0};
	std::vector<int> nums;
	for (int i=0; i<2; i++) {
		nums.push_back(a[i]);
	}
	Solution s;
	int longest_num = s.findMaxConsecutiveOnes(nums);
	std::cout << "result: " << longest_num << std::endl;

	std::vector<int> sort_arr_parity = {1,0,2};
	vector<int> sort_arr_ret = s.sortArrayByParity(sort_arr_parity);
	cout << "sort array by parity: ";
	s.showVec(sort_arr_ret);

	std::vector<int> sort_arr_parity_2 = {4,2,5,7};
	vector<int> sort_arr2_ret = s.sortArrayByParityII(sort_arr_parity_2);
	cout << "sort array by parity II: ";
	s.showVec(sort_arr2_ret);

	/* 
	std::vector<int> move_zero_vec = {0,1,0,3,12};
	s.moveZeroes(move_zero_vec);
	cout << "move zero: ";
	s.showVec(move_zero_vec);

	vector<int> ee = {1,3,5,6,8,9,11};
	vector<int> ff = {6,7,7,9,10};
	vector<int> res = s.merge(ee, ff);
	s.showVec(res);

	vector<int> aaaar = {17,18,5,4,6,1};
	vector<int> replace_vec = s.replaceElements(aaaar);
	s.showVec(replace_vec);

	vector<int> bbb_vec = {4,4,3,2,1}; // ; {0,3,2,1}
	bool ismountain = s.validMountainArray(bbb_vec);
	std::cout << "is mountain: " << ismountain << std::endl;

	longest_num = s.findMaxConsecutiveOnesBeginEnd(nums);
	std::cout << "result: " << longest_num << std::endl;

	int b[5] = {12,345,2,6,7896};
	std::vector<int> bb;
	for (int i=0; i<5; i++) {
		bb.push_back(b[i]);
	}
	int cnt = s.findNumbers(bb);
	cout << "cnt: " << cnt << endl;

	int c[5] = {-4,-1,0,3,10};
	std::vector<int> cc;
	for (int i=0; i<5; i++) {
		cc.push_back(c[i]);
	}
	vector<int> result = s.sortedSquares(cc);
	s.showVec(result);

	int d[8] = {1,0,2,3,0,4,5,0};
	std::vector<int> dd;
	for (int i=0; i<8; i++) {
		dd.push_back(d[i]);
	}
	// vector<int>::iterator it = dd.begin();
	// it += 2;
	// dd.insert(it, 9);
	s.duplicateZeros(dd);
	s.showVec(dd);

	vector<int> gg = {0,0,1,1,1,2,2,3,3,4};
	s.removeDuplicates(gg);
	cout << "remove duplicate: ";
	s.showVec(gg);

	vector<int> aaa = {3,1,7,11};
	bool aaa_ret = s.checkIfExist(aaa);
	cout << "result: " << aaa_ret << endl;
	*/


}
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;


/*
avoid integer sum overflow left + right
left + (right - left) / 2
*/

class Solution{
public:

	void showVector(std::vector<int> data) {
		std::vector<int>::iterator iter = data.begin();
		while(iter != data.end()) {
			cout << *iter << " ";
			iter ++;
		}
		cout << endl;
	}

	void show2DVector(std::vector< std::vector<int> > nums) {
		int n = nums.size();
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << nums[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	int removeDuplicates(std::vector<int>& nums) {
		if (nums.size() == 0) {return 0;}
		std::vector<int>::iterator it = nums.begin()+1;
		while (it != nums.end()) {
			if (*it == *(it - 1)) {;
				nums.erase(it);
			} else {
				it++;
			}
		}
		return nums.size();
	}

	int maxProfit(std::vector<int> prices) {
		int profit = 0;
		int buy = prices[0];
		for (int i=1; i<prices.size(); i++) {
			if (prices[i] > prices[i-1]) {
				// sell
				profit = max(profit, prices[i] - buy);
			} else {
				// buy
				buy = min(buy, prices[i]);
			}
		}
		return profit;
	}


	int maxProfit2(std::vector<int> data) {
		int res = 0, n = data.size();
		for (int i=0; i<n-1; i++) {
			if (data[i] < data[i+1]) {
				res += data[i+1] - data[i];
			}
		}
		return res;
	}

	void rotate(std::vector<int>& nums, int k) {
		if (nums.empty() || (k %= nums.size()) == 0) return;
		int n = nums.size();
		for (int i=0; i<n-k; i++) {
			nums.push_back(nums[0]);
			nums.erase(nums.begin());
		}
	}

	bool containsDuplicate_sort(std::vector<int>& nums) {
		bool ret = false;
		sort(nums.begin(), nums.end());
		int dup = nums[0], n = nums.size();
		for (int i=1; i<n; i++) {
			if (dup == nums[i]) {
				ret = true;
				break;
			} else {
				dup = nums[i];
			}
		}
		return ret;
	}

	bool containsDuplicate(std::vector<int>& nums) {
		set<int> tmp;
		int n = nums.size();
		for (int i=0; i<n; i++) {
			tmp.insert(nums[i]);
		}
		if (tmp.size() < n) {
			return true;
		} else {
			return false;
		}
	}

	int singleNumber(std::vector<int> nums) {
		unordered_set<int> st;
		for (int num : nums) {
			if (st.count(num)) st.erase(num);
			else st.insert(num);
		}
		return *st.begin();
	}

	int singleNumber_xor(std::vector<int> nums) {
		int res  = 0;
		for (auto num : nums) {
			res ^= num;
		}
		return res;
	}

	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
		unordered_map<int, int> m;
		vector<int> res;
		for (auto a : nums1) {m[a] += 1;}
		for (auto a : nums2) {
			if (m[a]-- > 0) {
				res.push_back(a);
			}
		}
		return res;
	}

	std::vector<int> plusOne(std::vector<int>& digits) {
		int N = digits.size();
		for (int i = N-1; i>=0; i--) {
			if (digits[i] == 9) digits[i] = 0;
			else {
				digits[i] += 1;
				return digits;
			}
		}
		if (digits.front() == 0) digits.insert(digits.begin(), 1);
		return digits;
	}

	void moveZero(std::vector<int>& nums) {
		int n = nums.size();
		for(int i=0, j=0; i<n; i++) {
			if (nums[i]) {
				swap(nums[i], nums[j++]);
			}
		}
	}

	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> ret;
		int n = nums.size();
		for(int i=0; i<n; i++) {
			int substract = target - nums[i];
			for(int j=i+1; j<n; j++){
				if(nums[j] == substract){
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}
		return ret;
	}

	void rotate(std::vector< vector<int> >& matrix) {
		int n = matrix.size();
		for(int i=0; i<n-1; i++) {
			for (int j=0; j<n-1; j++) {
				swap(matrix[i][j], matrix[n-1-j][n-1-i]);
			}
		}
		reverse(matrix.begin(), matrix.end());
	}

	std::vector<int> mergeSortedArrays(std::vector<int> nums1, std::vector<int> nums2) {
		std::vector<int> ret;
		int i = 0, j = 0;
		while ((i < nums1.size()) && (j < nums2.size())) {
			if (nums1[i] < nums2[j]) {
				ret.push_back(nums1[i]);
				i += 1;
			} else {
				ret.push_back(nums2[j]);
				j += 1;
			}
		}
		if (i < nums1.size()) {
			while(i < nums1.size()) {
				ret.push_back(nums1[i]);
				i += 1;
			}
		}
		if (j < nums2.size()) {
			while(j < nums1.size()) {
				ret.push_back(nums1[j]);
				j += 1;
			}
		}
		return ret;
	}

	int maxProfit3(std::vector<int> prices) {
		if (prices.size() <= 1) return 0;
		int n = prices.size();
		int global[3] = {0}, local[3] = {0};
		for (int i=1; i<n; i++) {
			int diff = prices[i] - prices[i-1];
			for (int j=1; j<3; j++) {
				local[j] = max(global[j-1] + max(0, diff), local[j]+diff);
				global[j] = max(global[j], local[j]);
				
			}
		}
		return global[2];
	}

	int firstBadVersion(int n) {
		int left = 1, right = n;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (isBadversion(mid)) {
				// boundary is at left
				right = mid;
			}
			else {
				// boundary is at right
				left = mid + 1;
			}
		}
		return left;
	}

};

int main(){
	std::vector<int> data = {0,0,1,1,1,2,2,3,3,4};
	Solution s;
	int ret = s.removeDuplicates(data);
	cout << "removeDuplicates: " << ret << endl; 

	std::vector<int> stock_price = {1,2};
	int max_profit = s.maxProfit(stock_price);
	cout << "max_profit: " << max_profit << endl;

	std::vector<int> nums = {1,2,3,4,5,6,7};
	s.rotate(nums, 3);
	s.showVector(nums);

	std::vector<int> dup_nums = {1,1,1,3,3,4,3,2,4,2};
	bool is_dup = s.containsDuplicate(dup_nums);
	cout << "is dup: " << is_dup << endl; 

	std::vector<int> sin_nums = {4,1,2,1,2};
	ret = s.singleNumber_xor(sin_nums);
	cout << "single numbers : " << ret << endl;

	std::vector<int> nums1 = {4,9,5};
	std::vector<int> nums2 = {9,4,9,8,4};
	std::vector<int> inter_result = s.intersect(nums1, nums2);
	s.showVector(inter_result);

	std::vector<int> digits = {9,9,9,9,9};
	std::vector<int> plus_result = s.plusOne(digits);
	cout << "plus one results: ";
	s.showVector(plus_result);

	std::vector<int> move_zero = {0,1,0,3,12};
	s.moveZero(move_zero);
	cout << "move zero: ";
	s.showVector(move_zero);

	std::vector<int> two_sum = {2,7,11,15};
	std::vector<int> sum_result = s.twoSum(two_sum, 9);
	cout << "two sum: ";
	s.showVector(sum_result);

	std::vector< std::vector<int> > matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	s.show2DVector(matrix);
	s.rotate(matrix);
	s.show2DVector(matrix);

	std::vector<int> a = {1, 2, 4, 6};
	std::vector<int> b = {2, 5, 6};
	std::vector<int> merge_ret = s.mergeSortedArrays(a,b);
	s.showVector(merge_ret);

	std::vector<int> prices3 = {1,2,3,4,5};
	int max_profit3 = s.maxProfit3(prices3);
	cout << "max profit3 result: " << max_profit3 << endl;

}


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
	Solution() {};
	~Solution() {};
	

	template<typename T>
	T fourSumCount(std::vector<T>& num1, std::vector<T> num2,
					 std::vector<T>& num3, std::vector<T> num4) {
		T res = 0;
		unordered_map<T, T> hash_map;
		for(auto n1 : num1) {
			for (auto n2 : num2) {
				++hash_map[n1 + n2];
			}
		}

		for (auto n3 : num3) {
			for (auto n4 : num4) {
				T target = -1 * (n3 + n4);
				res += hash_map[target];
			}
		}
		return res;
	}

	template<typename T>
	void show_hashmap(unordered_map<T, T> hash_map) {
		int size = hash_map.size();
		for (auto item : hash_map) {
			cout << item.first << ", " << item.second << endl;
		}
	}

	template<typename T>
	void show_vector(std::vector< std::vector<T> > nums) {
		for (auto num : nums) {
			show_vector(num);
		}
	}

	template<typename T>
	void show_vector(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << ", ";
		}
		cout << endl;
	}

	template<typename T>
	std::vector< std::vector<T> > fourSum(std::vector<T> nums, T target) {
		std::set< std::vector<T> > res;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				if (j > i + 1 && nums[j] == nums[j-1]) continue;
				int left = j+1, right = n-1;
				while(left < right) {
					T sum = nums[i] + nums[j] + nums[left] + nums[right];
					cout << "target: " << sum << endl;
					if (sum == target) {
						res.insert({nums[i], nums[j], nums[left], nums[right]});
						++left; --right;
					} else if (sum < target) {
						++left;
					} else {
						--right;
					}
				}
			}
		}
		return std::vector< std::vector<T> >(res.begin(), res.end());
	} 
};

int main(int argc, char const *argv[])
{
	std::vector<int> num1 = {1,2};
	std::vector<int> num2 = {-2, -1};
	std::vector<int> num3 = {-1, 2};
	std::vector<int> num4 = {0, 2};
	Solution s;

	int res = s.fourSumCount(num1, num2, num3, num4);
	cout << "four sum count result: " << res << endl;

	std::vector<int> nums = {2,2,2,2,2};
	std::vector< std::vector<int> > res_vec = s.fourSum(nums, 8);
	cout << "four sum result: " << endl;
	s.show_vector(res_vec);

	return 0;
}
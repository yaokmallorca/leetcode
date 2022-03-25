#include <iostream>
#include <string>
#include <cstring> // strcmp
#include <vector>
#include <map>
#include <algorithm> // count
#include <set>
#include <queue>
#include <map>
#include <utility> // pair

using namespace std;

class Solution
{
public:
	std::vector<string> fizzBuzz(int n) {
		std::vector<string> ret;
		for(int i=1; i<=n; ++i) {
			if (i % 15 == 0 && i >= 15) {
				ret.push_back("FizzBuzz");
			} else if (i % 3 == 0 && i >= 3) {
				ret.push_back("Fizz");
			} else if (i % 5 == 0 && i >= 5) {
				ret.push_back("Buzz");
			} else {
				ret.push_back(to_string(i));
			}
		}
		return ret;
	}

	void showVec(std::vector<string> strs) {
		for (auto str : strs) {
			cout << str.c_str() << " ";
		}
		cout << endl;
	}

	int majorityElement(std::vector<int>& nums) {
		int len = nums.size();
		map<int, int> temp;
		int max_cnt = 0, ret = 0;
		for (auto num : nums) {
			int cnt = temp.count(num);
			if (cnt > 0)
				temp[num] += 1;
			else
				temp[num] = 1;
			if (temp[num] > max_cnt) {
				ret = num;
			}
		}
		return ret;
	}

	// 204
	int countPrimes(int n) {
		int res = 0;
		std::vector<bool> prime(n, true);
		for (int i=2; i<n; ++i) {
			if (!prime[i]) continue;
			++res;
			for (int j=2; i*j<n; ++j) {
				prime[i*j] = false;
			}
		}
		return res;
	}

	//.118
	std::vector< std::vector<int> > generate(int numRows) {
		if (numRows == 1) return {{1}};
		std::vector< std::vector<int> > res;
		std::vector<int> pre_line = {1};
		res.push_back(pre_line);
		pre_line = {1, 1};
		res.push_back(pre_line);
		for (int i=3; i<=numRows; ++i) {
			std::vector<int> cur_line(i, 0);
			generateLine(pre_line, cur_line, res);
			pre_line = cur_line;
		}
		return res;
	}

	void generateLine(std::vector<int> pre_line, 
		std::vector<int>& cur_line, std::vector< std::vector<int> >& res) {
		for(int i=0; i<cur_line.size(); ++i) {
			if (i == 0 || i == cur_line.size()-1) {
				cur_line[i] = 1;
				continue;
			}
			cur_line[i] = pre_line[i] + pre_line[i-1];
		}
		res.push_back(cur_line);
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	void showVec(std::vector< std::vector<int> > res) {
		for (int i=0; i<res.size(); ++i) {
			std::vector<int> nums = res[i];
			showVec(nums);
		}
	}
};

int main() {
	Solution s;
	std::vector<string> ret = s.fizzBuzz(5);
	s.showVec(ret);

	std::vector<int> nums = {1,1,1,1,1,2,2,3,3};
	int max_cnt = s.majorityElement(nums);
	cout << "max count: " << max_cnt << endl;


	int nn = 20;
	int num_primes = s.countPrimes(nn);
	cout << "number of primes: " << num_primes << endl;

	int numRows = 30;
	std::vector< std::vector<int> > triangle = s.generate(numRows);
	s.showVec(triangle);


}
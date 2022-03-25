#include <iostream>
#include <string>
#include <cstring> // strcmp
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <map>
#include <climits>
#include <iterator> // iterator
#include <algorithm> // reverse
#include <utility> // pair

using namespace std;

class Solution
{
public:
	std::vector<int> getRow(int rowIndex) {
		std::vector<int> res(rowIndex+1);
		res[0] = 1;
		for(int i=1; i<=rowIndex; ++i) {
			for (int j=i; j>=1; --j) {
				cout << res[j-1] 
				res[j] += res[j-1];

			}
		}
		return res;
	}

	std::vector< std::vector<int> > lineGrowth(int numRows) {
		std::vector< std::vector<int> > res;
		res.push_back({1});
		res.push_back({1,1});
		for(int i=2; i<numRows; ++i) {
			std::vector<int> pre_line = res[i-1];
			std::vector<int> cur_line(i+1, 1);
			for(int j=1; j<=(i+1); ++j) {
				int a = j-1>=0 ? pre_line[j-1] : 0;
				cur_line[j] = a + pre_line[j];
			}
			res.push_back(cur_line);
		}
		return res;
	}

	std::vector< std::vector<int> > generate(int numRows) {
		std::vector< std::vector<int> > res(numRows, std::vector<int>());
		for (int i=0; i<numRows; ++i) {
			res[i].resize(i+1, 1);
			for (int j=1; j<i; ++j) {
				res[i][j] = res[i-1][j-1] + res[i-1][j];
			}
		}
		return res;
	}

	template<typename T>
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	template<typename T>
	void showVec(std::vector< std::vector<T> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}
};

int main() {
	Solution s;
	std::vector< std::vector<int> > res;
	res = s.generate(7);
	s.showVec(res);

	std::vector<int> row = s.getRow(6);
	s.showVec(row);
	return 0;
}
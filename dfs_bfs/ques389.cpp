#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	std::vector<int> lexicalOrder(int n) {
		std::vector<int> res;
		for (int i = 1; i <= 9; ++i) {
			lexicalPreOrder(i, n, res);
		}
		// showVec(res);
		return res;
	}

	void lexicalPreOrder(int cur, int n, std::vector<int>& nums) {
		if (cur <= n) {
			nums.push_back(cur);
			for (int i = 0; i < 10; ++i) {
				/* code */
				if (cur * 10 + i <= n)
					lexicalPreOrder(cur * 10 + i, n, nums);
				else break;
			}
		}
	}

	void lexicalPreOrder1(int cur, int n, std::vector<int>& nums) {
		if (cur > n) return;
		nums.push_back(cur);
		for (int i=0; i<10; ++i) {
			if (cur*10 + i <= n) {
				lexicalPreOrder(cur*10 + i, n, nums);
			} else break;
		}
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}


};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> res = s.lexicalOrder(13);
	s.showVec(res);
	return 0;
}
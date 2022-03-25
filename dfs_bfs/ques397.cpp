#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int integerReplacement(int n) {
		if (n <= 1) return 0;
		if (n % 2 == 0) return 1+integerReplacement(n / 2);
		else {
			long long t = n;
			return 2 + min(integerReplacement((t+1) / 2), integerReplacement((t-1) / 2));
		}
	}

	/*
	void integerReplacementDFS(int n, int cur, std::vector<int>& res) {
		if (cur <= 1) {
			res.push_back(cur);
			return;
		}
		if (cur % 2 == 0) integerReplacementDFS(cur%2, res);
		else {
			if (cur + 1 < n){
				integerReplacementDFS(n+1, res);
			} else {
				integerReplacementDFS(n-1, res);
			}
		}
	}
	*/

	void showVec(std::vector<int>& nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
	
};


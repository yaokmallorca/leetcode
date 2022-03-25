#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int fib(int n) {
		std::vector<int> fn(n+1, 0);
		fn[0] = 0; fn[1] = 1; fn[2] = 1;
		for (int i = 3; i <= n; ++i){
			/* code */
			fn[i] = fn[i-1] + fn[i-2] + fn[i-3];
		}
		showVec(fn);
		return fn.back();
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
	cout << s.fib(25) << endl;
	return 0;
}

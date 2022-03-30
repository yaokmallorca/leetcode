#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int nthUglyNumber(int n) {
		std::vector<int> prime = {2, 3, 5};
		std::vector<int> dp(n+1, 0);
		

	}

};

int main(int argc, char const *argv[])
{
	int n = 10; // [1, 2, 3, 4, 5, 6, 8, 9, 10, 12]
	Solution s;
	cout << s.nthUglyNumber(n) << endl;
	return 0;
}


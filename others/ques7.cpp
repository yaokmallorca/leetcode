#include <stdlib.h>
#include <iostream>
#include <climits>

using namespace std;

class Solution
{
public:
	int reverse(int x) {
		int res = 0, tmp = abs(x);
		while (tmp > 0) {
			if (abs(res) > INT_MAX / 10) return 0;
			res = tmp % 10 + res * 10;
			tmp = tmp / 10;
		}
		return x<0 ? -res : res;
	}
	
};

int main(int argc, char const *argv[])
{
	/* code */
	int x = -321;
	Solution s;
	int res = s.reverse(x);
	cout << "res: " << res << endl;
	return 0;
}
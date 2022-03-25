#include <stdlib.h>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int num = 0;
		for (int i = x; i>0 ; i/=10) {
			/* code */
			num += i*10;
			cout << num << endl;
		}
		return num == x ? true : false;
	}
};

int main(int argc, char const *argv[])
{
	int x = 121;
	Solution s;
	cout << s.isPalindrome(x) << endl;
	return 0;
}
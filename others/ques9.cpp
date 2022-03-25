#include <stdlib.h>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:

	// On !!!!
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int div = 1, num = x;
		int left = 0, right = 0;
		while (num > 10) {div *= 10; num /= 10;}
		cout << "div: " << div << endl;
		while (div > 0) {
			left = x / div;
			right = x % 10;

			if (left != right) return false;
			x = (x % div) / 10;
			div /= 100;
			cout << "l: " << left << ", r: " << right 
				 << ", d: " << div << ", x: " << x << endl;

		}
		return true;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	int x = 121;
	cout << s.isPalindrome(x) << endl;
	return 0;
}

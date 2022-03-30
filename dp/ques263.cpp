#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool isUgly(int n) {
		while (n >= 2) {
			if (n % 2 == 0) n /= 2;
			else if (n % 3 == 0) n /= 3;
			else if (n % 5 == 0) n /= 5;
			else return false;
		}
		return n == 1;
	}
	
};

int main(int argc, char const *argv[])
{
	Solution s;
	int n1 = 6, n2=1, n3=14;
	cout << s.isUgly(n1) << endl;
	cout << s.isUgly(n2) << endl;
	cout << s.isUgly(n3) << endl;
	return 0;
}
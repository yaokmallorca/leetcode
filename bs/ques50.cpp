#include <stdlib.h>
#include <iostream>

using namespace std;

class Solution
{
public:
	double myPow(double x, int n) {
		double res = 1.f;
		for (int i=n; i!=0; i/=2) {
			/* code */
			if (i % 2 != 0) res *= x;
			x *= x;
		}
		return (n<0) ? 1/res : res;
	}
	
	int mySqrt(int x) {
		int left = 1, right = x;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (mid <= x / mid) left = mid + 1;
			else right = mid;
		}
		return right-1;
	}
};


int main(int argc, char const *argv[]) {
	Solution s;

	double x_in = 2.0f;
	double pow_result = s.myPow(x_in, 11);
	cout << "myPow: " << pow_result << endl;

	double sqrt_res = s.mySqrt(4);
	cout << "mySqrt: " << sqrt_res << endl;
	return 0;
}

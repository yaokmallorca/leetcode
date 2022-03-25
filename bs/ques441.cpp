#include <stdlib.h>
#include <iostream>

using namespace std;

class Solution
{
public:

	// Sn = n*(a_0 + a_n) / 2
	int arrangeCoins(int n) {
		if (n <= 1) return n;
		long left = 1, right = n;
		while (left < right) {
			long mid = left + (right - left) / 2;
			long sn = mid * (1 + mid) / 2;
			if (sn < n) left = mid + 1;
			else right = mid;
		}
		return left - 1;
	}

	double myPow_bi(int x, int n) {
		double res = 1.0f;
		for (int i=n; i!=0; i/=2) {
			if (i%2 != 0) res *= x;
			x *= x;
			cout << "binary method: " << i << ", " << x << endl;
		}
		cout << "<<<<<<<<<<<<<<<" << endl;
		return n<0 ? 1/res : res;
	}

	double myPow_bf(int x, int n) {
		double res = 1.f;
		for (int i = 0; i < n; ++i) {
			/* code */
			cout << "bf method: " << i << endl;
			res *= x;
		}
		cout << "<<<<<<<<<<<<<<<" << endl;
		return n<0 ? 1/res : res;
	}
	
};

int main(int argc, char const *argv[])
{
	Solution s;

	int num_rows = s.arrangeCoins(8);
	cout << num_rows << endl;

	double pow_res_bi = s.myPow_bi(2, 10);
	// double pow_res_bf = s.myPow_bf(2, 10);
	cout << pow_res_bi << endl;


	return 0;
}
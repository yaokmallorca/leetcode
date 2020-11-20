#include <iostream>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int tmp = x;
		if (x < 0)
			return false;
		long ret = 0;
		while (x/10 != 0){
			ret = (x%10) + ret*10;
			x = x/10;
		}
		ret = (x%10) + ret*10;
		if (ret == tmp) return true;
		else return false;
	}
};

int main() {
	int a = 121;
	Solution s;
	bool ret = s.isPalindrome(a);
	cout << "result: " << ret << endl; 
	return 0;
}
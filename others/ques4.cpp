#include <stdlib.h>
#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution
{
public:
	int myAtoi(string s) {
		if (s.empty()) return 0;
		int sign = 1, base = 0, i = 0, n = s.size();
		while (i < n && s[i] == ' ') ++i;
		if (i<n && (s[i] == '-' || s[i] == '+')) {
			sign = s[i] == '-' ? -1 : 1;
			++i;
		}
		while(i < n && s[i] <= '9' && s[i] >= '0') {
			if (base > INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7)) {
				return (sign == 1) ? INT_MAX : INT_MIN;
			}
			base = base*10 + (s[i++] - '0');
		}
		return base*sign;
	}
};

int main(int argc, char const *argv[]) {
	string str = "-493";
	Solution s;
	int result = s.myAtoi(str);
	cout << "result: " << result << endl;

	return 0;
}
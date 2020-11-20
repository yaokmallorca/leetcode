#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

class Solution {
public:
	int reverse_math(int x) {
		long ret = 0;
		while (x/10 != 0){
			ret = (x%10) + ret*10;
			x = x/10;
		}
		ret = (x%10) + ret*10;
		return (ret > INT_MAX || ret < INT_MIN) ? 0 : ret;
	}

	int reverse_str(int x) {
		string x_str = to_string(x);
		int len = strlen(x_str.c_str());
		char data[len+1];
		strcpy(data, x_str.c_str());
		// char* data = x_str.c_str();
		char data_ret[len+1];
		for (int i=0; i<len; i++ ) {
			data_ret[len-1-i] = data[i];
		}
		string x_ret_str(data_ret);
		long ret = stol(x_ret_str);
		if (ret <= INT_MAX) return ret;
		if (-ret >= INT_MIN) return -ret;
		return 0;
	}
};


int main(){
	int a = 1534236469;
	int ret = 0;
	Solution s;

	ret = s.reverse_math(a);
	cout << "result: " << ret << endl;

}
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <regex>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int N = str.size();
		if (N == 0) {return 0;}
		// regex pattern("\\^-[0-9]+|^[0-9]+|^([\\s]+)-[0-9]+");
		regex pattern("^\\s*([+-]?\\d+)");
		smatch result;
		string::const_iterator iterstart = str.begin();
		string::const_iterator iterend = str.end();
		string ret;
		while (regex_search(iterstart, iterend, result, pattern)) {
			ret = result[0];
			break;
			iterstart = result[0].second;
		}
		cout << ret.c_str() << endl;
		regex change("\\s+|\\+*");
		ret = regex_replace(ret, change, "");
		// change = "\\+*";
		// ret = regex_replace(ret, change, "");
		cout << ret.c_str() << endl;

		int num_len = ret.size();
		bool is_neg = false;
		long long result_int = 0;
		for(int i=0; i<num_len; i++) {
			if (ret[i] == '-'){
				is_neg = true;
				continue;
			}
			result_int += (ret[i] - '0')*pow(10, num_len-i-1);
		}
		if(is_neg)
			result_int = (result_int) * -1;
		if (result_int >= INT_MAX)
			return INT_MAX;
		if (result_int <= INT_MIN)
			return INT_MIN;
		return result_int;
	}

	float myAtof(string str) {
		int N = str.size();
		if (N == 0) {return 0;}
		regex pattern("\\^-[0-9]+(.[0-9]+)?|^[0-9]+(.[0-9]+)?|^([\\s]+)-[0-9]+(.[0-9]+)?");
		smatch result;

		string::const_iterator iterstart = str.begin();
		string::const_iterator iterend = str.end();
		string ret;
		while (regex_search(iterstart, iterend, result, pattern)) {
			ret = result[0];
			break;
			iterstart = result[0].second;
		}
		cout << "ret: " << ret.c_str() << endl;
		int num_len = ret.size();
		bool is_neg = false;
		bool is_dem = false;
		int start_dem = 0;
		float result_int = 0;
		for(int i=0; i<num_len; i++) {
			if (ret[i] == '-'){
				is_neg = true;
				continue;
			}
			if (ret[i] == '.'){
				is_dem = true;
				start_dem = i;
			}
			result_int += (ret[i] - '0')*pow(10, num_len-i-1);
			if(is_dem){
				cout << "start_dem: " << i-start_dem+1 << ", " << ((ret[i] - '0')*pow(0.1, i-start_dem+1)) << endl;
				result_int += (ret[i] - '0')*pow(0.1, i-start_dem+1);
			}
		}
		if(is_neg)
			result_int = (result_int) * -1;
		return result_int;
	}
};

int main() {
	string str = "absc123471bb123"; // "   -42";
	Solution s;
	int ret = s.myAtoi(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;

	str = "   -42cc132";
	ret = s.myAtoi(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;

	str = "4193 with words";
	ret = s.myAtoi(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;

	str = "words and 987";
	ret = s.myAtoi(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;

	str = "42";
	ret = s.myAtoi(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;

	str = "-91283472332";
	ret = s.myAtoi(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;

	str = "+1";
	ret = s.myAtoi(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;

	/*
	str = "words and 987.881 nd";
	float b = s.myAtof(str);
	cout << "result: " << b << endl;
	cout << "###############" << endl;
	*/
	return 0;
}
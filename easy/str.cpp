#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if ( strcmp(haystack.c_str(), needle.c_str()) == 0 )
			return 0;
		int pos = haystack.find(needle);
		if (pos != string::npos){
			return pos;
		} else{
			return -1;
		}
	}
};

int main() {
	string str = "hello";
	string needle = "ll";

	Solution s;
	int ret = s.strStr(str, needle);
	cout << "result: " << ret << endl;

	str = "aaaaa";
	needle = "bba";
	ret = s.strStr(str, needle);
	cout << "result: " << ret << endl;

	str = "aaaaa";
	needle = "aaaaa";
	ret = s.strStr(str, needle);
	cout << "result: " << ret << endl;

	str = "";
	needle = "";
	ret = s.strStr(str, needle);
	cout << "result: " << ret << endl;

	return 0;
}
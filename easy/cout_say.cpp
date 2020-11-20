#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
	
	string countAndSay(int n) {
		if (n == 1) return "1";
		string str = countAndSay(n-1);

		string result = "";
		int index = 0;
		while(index < str.size()) {
			char curr = str[index];
			int cursor = index, count = 0;
			while (curr == str[cursor] && index < str.size()) {
				cursor ++;
				count ++;
			}
			char number = count + '0';
			result += number;
			result += curr;
			index += count;
		}
		return result;
	} 
	/*
	string countAndSay(int n) {
		string result = "";
		for(int i=0; i<n; i++) {
			char number = i + '0';
			result += number;
		}
		return result;
	}*/

};

int main(int argc, char const *argv[])
{
	/* code */
	int a = 6;
	Solution s;
	string ret = s.countAndSay(a);
	cout << "result: " << ret.c_str() << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		deque<char> d;
		for (char c : s){
			switch (c) {
				case '(': case  '[': case  '{':
					d.push_back(c);
					break;
				case  ')':
					if ( d.size()!=0 && d.back() == '(') {
						d.pop_back();
						break;
					} else {
						return false;
					}
				case  ']':
					if ( d.size()!=0 && d.back() == '[') {
						d.pop_back();
						break;
					} else {
						return false;
					}
				case  '}':
					if ( d.size()!=0 && d.back() == '{') {
						d.pop_back();
						break;
					} else {
						return false;
					}
				default:
					return false;
			}
		}
		return (d.size() == 0) ? true : false;
	}
};


int main() {
	// string str = "{[]}";
	string str = "(){}}{";
	Solution s;
	bool ret = s.isValid(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;
	
	str = "([)]";
	ret = s.isValid(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;

	str = "(]";
	ret = s.isValid(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;
	
	str = "()";
	ret = s.isValid(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;

	str = "()[]{}";
	ret = s.isValid(str);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;
	
	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
	bool isValid(string s) {
		stack<char> parentheses;
		for(auto c : s) {
			if (c == '(' || c == '[' || c == '{') parentheses.push(c);
			else {
				if (parentheses.empty()) return false;
				if (c == ')' && parentheses.top() != '(') return false;
				if (c == ']' && parentheses.top() != '[') return false;
				if (c == '}' && parentheses.top() != '{') return false;
				parentheses.pop();
			}
		}
		return parentheses.empty();
	}
	

};

int main(int argc, char const *argv[])
{
	string str =  "([)]"; // "([)";
	Solution s;
	cout << s.isValid(str) << endl;
	return 0;
}
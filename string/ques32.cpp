#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
	int longestValidParentheses1(string s) {
		stack<int> que;
		int n = s.size(), start = 0, res = 0;
		for (int i = 0; i < n; ++i) {
			/* code */
			if (s[i] == '(') que.push(i);
			else {
				// s[i] == ')'
				if (que.empty()) start = i+1; // do not have left parenthese before
				else {
					que.pop(); // get the previous left parenthese index
					if (que.empty()) {
						res = max(res, i - start + 1);
					} else {
						res = max(res, i - que.top());
					}
				}
			}
		}
		return res;
	}
	
	int longestValidParentheses(string s) {
        if (s.size() == 0) return 0;
		queue<int> que;
		int n = s.size(), res = 0, start = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '(') que.push(i);
            else if (s[i] == ')') {
            // else {
                if (que.empty()) start = i+1;
                else {
                    que.pop();
                    if (que.empty()) res = max(res, i - start + 1);
                    else {res = max(res, i - que.back()); }
                }
            }
        }
		return res;

	}
};

int main(int argc, char const *argv[])
{
	string str = "(()";
	Solution s;
	cout << s.longestValidParentheses(str) << endl;

	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	std::vector<string> generateParenthesis(int n) {
		std::vector<string> res;
		string out;
		generateParenthesisDFS(res, out, n, n);
		return res;
	}

	void generateParenthesisDFS(std::vector<string>& res, string& str, 
		int left, int right){
		if (left > right) return;
		if (left == 0 && right == 0) {res.push_back(str); return;}
		else {
			if(left  > 0) generateParenthesisDFS(res, str+'(', left-1, right);
			if(right > 0) generateParenthesisDFS(res, str+')', left, right-1);
		}
	}
	
};
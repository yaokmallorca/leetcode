#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> st;
		generateParenthesisDFS2(n, n, "", st);
		// return vector<string>(st.begin(), st.end());
		return st;
	}

	void generateParenthesisDFS1(int n, int left, int right, string out, vector<string> *ret) {
		if( out.size() == 2*n ){
			ret->push_back(out);
		}
		else {
			if (left < n){
				left += 1;
				out += "(";
				generateParenthesisDFS1(n, left, right, out, ret);
			}
			if (left > right){
				right += 1;
				out += ")";
				generateParenthesisDFS1(n, left, right, out, ret);
			}
		}
	}

	void generateParenthesisDFS2(int left, int right, string out, vector<string> &ret) {
		if (left > right) return;
		if (left == 0 && right == 0) {
			ret.push_back(out);
		}
		else {
			if (left > 0){
				generateParenthesisDFS2(left-1, right, out+'(', ret);
			}
			if (right > 0) {
				generateParenthesisDFS2(left, right-1, out+')', ret);
			}
		}
	}

	void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
		if (left > right) return;
		if (left == 0 && right == 0) res.push_back(out);
		else {
			if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
			if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res);
		}
	}

	int scoreOfParentheses1(string S) {
		int N = S.size();
		int left = N/2, right = N/2, score = 1;
		score = scoreOfParenthesesDFS(left, right, score, S);
		return score;
	}

	int scoreOfParenthesesDFS(int left, int right, int &score, string res_str) {
		if (left == 0 && right == 0) return score;
		std::size_t found_left;
		found_left = res_str.find("((");
		if (found_left == 0) {
			// remove the outmost (), and result * 2
			res_str = res_str.substr(1, res_str.size()-2);
			score = score * 2;
			scoreOfParenthesesDFS(left-1, right-1, score, res_str);
		} else {
			found_left = res_str.find("()");
			if (found_left == 0){
				res_str = res_str.substr(2, res_str.size()-2);
				score = score + 1;
				scoreOfParenthesesDFS(left-1, right-1, score, res_str);
			} else {
				return score;
			}
		}
		return score;
	}

	int scoreOfParentheses(string S) {
		int res = 0, cnt = 0, n = S.size();
		for (int i = 0; i < n; ++i) {
			(S[i] == '(') ? ++cnt : --cnt;
			if (S[i] == ')' && S[i - 1] == '('){
				res += (1 << cnt);
			} 
		}
		return res;
	}
};

int main() {
	vector<string> result;
	Solution s;
	result = s.generateParenthesis(3);

	cout << "result: ";
	for(vector<string>::iterator iter=result.begin(); iter!=result.end(); iter++) {
		cout << *iter << ", " ;
	}
	cout << endl;

	string S = "(()(()))";
	int score = s.scoreOfParentheses(S);
	cout << "score: " << score << endl;
}
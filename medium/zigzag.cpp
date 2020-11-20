#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
	int max(int a, int b) {
		return a > b ? a : b;
	}

	string convert(string s, int numRows) {
		int N = s.size();
		if (N <= 1) return s;
		if (numRows == 1) return s;
		string ret = "";
		
		vector<int> interval;
		interval.push_back(2 * (numRows - 1));
		for (int i=1; i<(numRows-1); i++) {
			interval.push_back(interval[0] - 2*i);
		}
		interval.push_back(interval[0]);
		int total = interval[0];
		string sub_each_line[numRows];
		for (int j = 0; j<numRows; j++) {
			int tmp = interval[j];
			int i=j;
			while (i<N) {
				int space = 0;
				sub_each_line[j] += s[i];
				space += tmp;
				if (total - space != 0 && i+tmp < N){
					sub_each_line[j] += s[i+tmp];
				}
				i += total;
			}
		}
		for(int i=0; i<numRows; i++){
			ret += sub_each_line[i];
		}
		return ret;
	}

	void showset(set<char> s) {
		set<char>::iterator iter = s.begin();
		while (iter != s.end()) {
			cout << *iter << " ";
			iter ++;
		}
		cout << endl;
	}

	int lengthOfLongestSubstring(string s) {
		int N = s.size();
		if (N <= 1) {return N;}
		int l = 0, r = 0, res = 0;
		set<char> sub;
		while(r<N) {
			while(sub.count(s[r])){
				sub.erase(s[l]);
				l++;
			}
			sub.insert(s[r]);
			res = max(res, sub.size());
			showset(sub);
			r++;
		}
		return res;
	}


};

int main() {
	string input = "";
	int nRows=0, ret=0;
	string res = "";

	Solution s;
	/*
	input = "abcabcbb";
	ret = s.lengthOfLongestSubstring(input);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;

	input = "pwwkew";
	ret = s.lengthOfLongestSubstring(input);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;
	*/

	input = "PAYPALISHIRING";
	cout << "input: " << input.size() << endl;

	res = s.convert(input, 4);
	cout << "result: " << res.c_str() << ", " << res.size() << endl;
	cout << "###############" << endl;

	res = s.convert(input, 3);
	cout << "result: " << res.c_str() << ", " << res.size() << endl;
	cout << "###############" << endl;

	input = "AB";
	res = s.convert(input, 1);
	cout << "result: " << res.c_str() << ", " << res.size() << endl;
	cout << "###############" << endl;




	return 0;
}
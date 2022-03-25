#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{
public:
	string minWindow1(string s, string t) {
		string res = "";
		unordered_map<char, int> letterCnt;
		int left = 0, cnt = 0, minLen = INT_MAX;
		for (char c : t) ++letterCnt[c];
		showMap(letterCnt);
		cout << "<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		for (int i = 0; i < s.size(); ++i) {
			if (--letterCnt[s[i]] >= 0) ++cnt;
			while (cnt == t.size()) {
				if (minLen > i - left + 1) {
					minLen = i - left + 1;
					res = s.substr(left, minLen);
				}
				if (++letterCnt[s[left]] > 0) --cnt;
				++left;
			}
			showMap(letterCnt);
			cout << "<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		}
		return res;
	}

	string minWindow(string s, string t) {
		string res = "";
		unordered_map<char, int> letterCnt;
		// unordered_map<char, int> wordFreq;
		int start=0, cnt=0, minLen=INT_MAX;
		for(auto c : t) {++letterCnt[c];}
		// showMap(letterCnt);

		for (int i = 0; i < s.size(); ++i) {
			/* code */
			// move right pt
			if (--letterCnt[s[i]] >= 0) {
				++cnt;
			}
			// move left pt
			while (cnt == t.size()) {
				int tmp = i - start + 1;
				if (tmp < minLen) {
					minLen = tmp;
					res = s.substr(start, minLen);
				}
				if (++letterCnt[s[start]]>0) --cnt;
				++start;
			}
			showMap(letterCnt);
			cout << "<<<<<<<<<<<<<<<<<<" << endl;
		}

		return res;
	}

	void showMap(unordered_map<char, int> umaps) {
		for (auto i : umaps) {
			cout << "( " << i.first << ", " << i.second << " ) ";
		}
		cout << endl;
	}

	void step() {
		char c = 0;
		cin >> c;
		cout << "###############" << endl;
	}
};

int main(int argc, char const *argv[])
{
	string str = "ADOBECODEBANC", t = "ABC";
	Solution s;
	cout << s.minWindow(str, t) << endl;

	return 0;
}


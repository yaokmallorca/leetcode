#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>

using namespace std;

class Solution
{
public:
	bool isScramble(string& s1, string& s2) {
		
		if (s1.size() != s2.size()) return false;
		if (s1 == s2) return true;
		int n = s1.size();
		string str1 = s1, str2 = s2;
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());
		if (str1 != str2) return false;
		for (int i = 1; i < n; ++i) {
			string s11 = s1.substr(0, i);
			string s12 = s1.substr(i);
			string s21 = s2.substr(0, i);
			string s22 = s2.substr(i);
			// don't rotate
			if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
			// rotate
			s21 = s2.substr(n - i);
			s22 = s2.substr(0, n - i);
			// if (isScramble(s11, s22) && isScramble(s12, s21)) return true;
			if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
		}
		return false;
		/* 
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 != str2) return false;
        for (int i = 1; i < s1.size(); ++i) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
            s21 = s2.substr(s1.size() - i);
            s22 = s2.substr(0, s1.size() - i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
        }
        return false;
        */
	}
	

};

int main(int argc, char const *argv[])
{
	Solution s;
	// s1 = "great", s2 = "rgeat"
	string s1 = "great", s2 = "rgeat";
	cout << s.isScramble(s1, s2) << endl;

	s1 = "abcde", s2 = "caebd";
	cout << s.isScramble(s1, s2) << endl;

	s1 = "abb", s2 = "bba";
	cout << s.isScramble(s1, s2) << endl;


	return 0;
}
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	void showSet(set<char> s) {
		set<char>::iterator i = s.begin();
		while (i!=s.end()) {
			cout << *i << " ";
			i++;
		}
		cout << endl;
	}

	int lengthOfLongestSubstring(string s) {
		int len = strlen(s.c_str());
		if (len <= 1) return len;
		int l = 0, r = 0, res = 0;
		set<char> sub;
		while (r<len){
			while (sub.count(s[r])){
				sub.erase(s[l]);
				l++;
			}
			sub.insert(s[r]);
			res = max(res, int(sub.size()));
			// res = sub.size();
			cout << "l: " << l << ", r: " << r << endl;
			showSet(sub);
			// cout << "<<<<<<<<<<<<" << endl;
			r++;
		}
		showSet(sub);
		return res;
	}

	int lengthOfLongestSubstringMap(string s) {
		const int N = s.size();
		if (N <= 1) return N;
		map<char, int> pos;
		int l = 0;
		int res = 0;
		for (int r = 0; r < N; ++r) {
			if (pos.count(s[r])) {
				l = max(l, pos[s[r]] + 1);
			}
			pos[s[r]] = r;
			res = max(res, r - l + 1);
		}
		return res;
	}

	bool istPalindrome(string s) {
		bool ret = true;
		int len = s.size();
		for(int i=0; i<(len/2); i++) {
			char a = s[i];
			char b = s[len-i-1];
			if (a != b){
				return false;
			}
		}
		return ret;
	}

	string longestPalindrome(string s) {
		const int N = s.size();
		if (N <= 1) {return s;}
		int l=0, r=0, sub_len = 0;
		string res = "";
		while(l<N) {
			r = l+1;
			string tmp = "";
			while(r <= N) {
				tmp = s.substr(l, r-l);
				if(istPalindrome(tmp) && sub_len < tmp.size()) {
					sub_len = tmp.size();
					res = tmp;
				}
				r++;
			}
			l++;
		}
		return res;
	}

	string manacher(string s) {
		int N = s.size();
		if(N <= 1) {return s;}

		string tmp_s = "$#";
		for(int i=0; i<N; i++) {
			tmp_s += s[i];
			tmp_s += "#";
		}
		
		N = tmp_s.size();
		std::vector<int> p(N, 0);
		int mx=0, id=0, resLen=0, resCen= 0;
		for(int i=0; i<N; i++) {
			p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
			while (tmp_s[i + p[i]] == tmp_s[i - p[i]]) ++p[i];
			if (mx < i + p[i]) {
				mx = i + p[i];
				id = i;
			}
			if (resLen < p[i]) {
				resLen = p[i];
				resCen = i;
			}
		}
		return s.substr((resCen - resLen) / 2, resLen - 1);
	}
};

int main() {
	string input = "abcabcbb";

	Solution s;
	/*
	int ret = 0;
	ret = s.lengthOfLongestSubstringMap(input);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;

	input = "bbbbb";
	ret = s.lengthOfLongestSubstringMap(input);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;


	input = "pwwkew";
	ret = s.lengthOfLongestSubstringMap(input);
	cout << "result: " << ret << endl;
	cout << "###############" << endl;
	*/

	input = "cbbc";
	string res = "";
	/*
	res = s.longestPalindrome(input);
	cout << "result: " << res.c_str() << endl;
	cout << "###############" << endl;

	input = "babad";
	res = s.longestPalindrome(input);
	cout << "result: " << res.c_str() << endl;
	cout << "###############" << endl;

	input = "cbbd";
	res = s.longestPalindrome(input);
	cout << "result: " << res.c_str() << endl;
	cout << "###############" << endl;

	input = "a";
	res = s.longestPalindrome(input);
	cout << "result: " << res.c_str() << endl;
	cout << "###############" << endl;

	input = "ac";
	res = s.longestPalindrome(input);
	cout << "result: " << res.c_str() << endl;
	cout << "###############" << endl;
	*/
	/*
	input = "klvxwqyzugrdoaccdafdfrvxiowkcuedfhoixzipxrkzbvpusslsgfjocvidnpsnkqdfnnzzawzsslwnvvjyoignsfbxkgrokzyusxikxumrxlzzrnbtrixxfioormoyyejashrowjqqzifacecvoruwkuessttlexvdptuvodoavsjaepvrfvbdhumtuvxufzzyowiswokioyjtzzmevttheeyjqcldllxvjraeyflthntsmipaoyjixygbtbvbnnrmlwwkeikhnnmlfspjgmcxwbjyhomfjdcnogqjviggklplpznfwjydkxzjkoskvqvnxfzdrsmooyciwulvtlmvnjbbmffureoilszlonibbcwfsjzguxqrjwypwrskhrttvnqoqisdfuifqnabzbvyzgbxfvmcomneykfmycevnrcsyqclamfxskmsxreptpxqxqidvjbuduktnwwoztvkuebfdigmjqfuolqzvjincchlmbrxpqgguwuyhrdtwqkdlqidlxzqktgzktihvlwsbysjeykiwokyqaskjjngovbagspyspeghutyoeahhgynzsyaszlirmlekpboywqdliumihwnsnwjc";
	res = s.longestPalindrome(input);
	cout << "result: " << res.c_str() << endl;
	cout << "###############" << endl;
	*/

	input = "babad";
	res = s.manacher(input);
	cout << "result: " << res.c_str() << endl;
	cout << "###############" << endl;

	input = "klvxwqyzugrdoaccdafdfrvxiowkcuedfhoixzipxrkzbvpusslsgfjocvidnpsnkqdfnnzzawzsslwnvvjyoignsfbxkgrokzyusxikxumrxlzzrnbtrixxfioormoyyejashrowjqqzifacecvoruwkuessttlexvdptuvodoavsjaepvrfvbdhumtuvxufzzyowiswokioyjtzzmevttheeyjqcldllxvjraeyflthntsmipaoyjixygbtbvbnnrmlwwkeikhnnmlfspjgmcxwbjyhomfjdcnogqjviggklplpznfwjydkxzjkoskvqvnxfzdrsmooyciwulvtlmvnjbbmffureoilszlonibbcwfsjzguxqrjwypwrskhrttvnqoqisdfuifqnabzbvyzgbxfvmcomneykfmycevnrcsyqclamfxskmsxreptpxqxqidvjbuduktnwwoztvkuebfdigmjqfuolqzvjincchlmbrxpqgguwuyhrdtwqkdlqidlxzqktgzktihvlwsbysjeykiwokyqaskjjngovbagspyspeghutyoeahhgynzsyaszlirmlekpboywqdliumihwnsnwjc";
	res = s.manacher(input);
	cout << "result: " << res.c_str() << endl;
	cout << "###############" << endl;

	return 0;
}
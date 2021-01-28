#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int len = s.size();
		for(int i=0; i<len/2; i++) {
			swap(s[i], s[len-1-i]);
		}
	}

	int reverseInteger(int x) {
		long ret = 0;
		while(x / 10 != 0){
			ret = (x%10) + ret*10;
			x = x / 10;
		}
		ret = (x%10) + ret*10;
		return (ret > INT_MAX || ret < INT_MIN) ? 0 : ret;
	}

	int firstUniqChar(string s) {
		unordered_map<char, int> m;
		for (char c : s) ++m[c];
		for (int i=0; i<s.size(); i++) {
			if (m[s[i]] == 1) return i;
		}
		return -1;
	}

	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		int m[26] = {0};
		for(char c : s) ++m[c - 'a'];
		for(char c : t) {
			if ( --m[c - 'a'] < 0) return false;
		}
		return true;
	}

	bool isPalindrome(string s) {
		bool ret = true;
		int n = s.size();
		int left = 0, right = n-1;
		while (left < right) {
			if (!isAlphaNum(s[left])){
				left+=1;continue;
			} 
			if (!isAlphaNum(s[right])){
				right-=1;continue;
			}
			if((s[left] + 32 - 'a')%32 != (s[right] + 32 - 'a')%32){
				ret = false;
				break;
			} else {
				left += 1;
				right -= 1;
			}
		}
		return ret;
	}

	bool isAlphaNum(char& c){
		if (c >= 'a' && c <= 'z') return true;
		if (c >= 'A' && c <= 'Z') return true;
		if (c >= '0' && c <= '9') return true;
		return false;
	}

	int myatoi(string str) {
		if (str.empty()) return 0;
		int sign = 1, base = 0, i = 0, n = str.size();
		while (i < n && str[i] == ' ') ++i;
		if (i < n && (str[i] == '+' || str[i] == '-')) {
			sign = (str[i++] == '+') ? 1 : -1;
		}
		while (i < n && str[i] >= '0' && str[i] <= '9') {
			if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
				return (sign == 1) ? INT_MAX : INT_MIN;
			}
			base = 10 * base + (str[i++] - '0');
		}
		return base * sign;
	}

	int strStr(string haystack, string needle) {
		if ( strcmp(haystack.c_str(), needle.c_str()) == 0){
			return 0;
		}
		int pos = haystack.find(needle);
		if (pos != string::npos) {
			return pos;
		} else {
			return -1;
		}
	}

	string countAndSay(int n) {
		if (n <= 0) return "";
		string res = "1";
		while (--n) {
			string cur = "";
			for (int i=0; i<res.size(); i++) {
				int cnt = 1;
				while(i+1<res.size() && res[i]==res[i+1]) {
					++cnt;
					++i;
				}
				// cout << "cnt: " << cnt << ", res: " << res.c_str() << endl;
				cur += to_string(cnt) + res[i];
				// cout << "#####################" << endl;
			}
			res = cur;
			// cout << "res: " << res.c_str() << endl;
		}
		return res;
	}

	string longestCommonPrefix(std::vector<string>& strs) {
		if (strs.empty()) return "";
		if (strs.size() == 1) return strs[0];
		string begin = strs[0], ret = "";
		int n = strs.size();
		int max_len = 0;
		for(int j=begin.size(); j>0; j--) {
			string sub_str = begin.substr(0, j);
			int common_nums = 0;
			for(int i=1; i<n; i++) {
				size_t found = strs[i].find(sub_str);
				if ((found != string::npos) && (found == 0)) {
					++common_nums;
				}
			}
			if (common_nums == n-1){
				int tmp_len = sub_str.size();
				if (tmp_len > max_len) {
					max_len = tmp_len;
					ret = sub_str;
				}
			}
		}
		return ret;
	}

	void showString(std::vector<char> str) {
		for(auto s : str) {
			cout << s << ' ';
		}
		cout << endl;
	}
};

int main(){
	std::vector<char> reverse_str = {'H','a','n','n','a','h'};
	Solution s;
	s.reverseString(reverse_str);
	cout << "reverse results: ";
	s.showString(reverse_str);

	int a = -986;
	int b = s.reverseInteger(a);
	cout << "reverse interger result: " << b << endl;

	string str = "aadadaad";
	int first_uniq_index  = s.firstUniqChar(str);
	cout << "first unique char is at " << first_uniq_index << endl;

	string str1 = "anagram", str2 = "car";
	bool anagram_result = s.isAnagram(str1, str2);
	cout << "anagram result: " << anagram_result << endl;

	string palin = "rac a car";
	bool is_palin = s.isPalindrome(palin);
	cout << "Palindrome result: " << is_palin << endl;

	string number = "-+12";
	int atoi_ret = s.myatoi(number);
	cout << "myatoi result: " << atoi_ret << endl;

	string count_say_ret = s.countAndSay(6);
	cout << "count and say results: " << count_say_ret.c_str() << endl;

	std::vector<string> strs = {"flower", "flower", "flower", "flower"};
	string longest_common_str = s.longestCommonPrefix(strs);
	cout << "longest common string: " << longest_common_str.c_str() << endl;
}
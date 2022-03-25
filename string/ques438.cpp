#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	std::vector<int> findAnagrams1(string s, string p) {
		std::vector<int> res;
		int left = 0, right = p.size(), n = s.size(), cnt = right;
		unordered_map<char, int> umap;
		for(auto c : p) ++umap[c];

		while(right <= n) {
			if (umap[s[right++]]-- >= 1) --cnt;
			if (cnt == 0) res.push_back(++left); 
			if (right - left == p.size() && umap[s[left++]] > 0) ++cnt;
		}
		return res;
	}

	std::vector<int> findAnagrams(string s, string p) {
		if (s.empty()) return {};
		vector<int> res, m(256, 0);
		int left = 0, right = 0, cnt = p.size(), n = s.size();
		for (char c : p) ++m[c];
		while (right < n) {
			if (m[s[right++]]-- >= 1) --cnt;
			if (cnt == 0) res.push_back(left);
			if (right - left == p.size() && m[s[left++]]++ >= 0) ++cnt;
		}
		return res;
	}

	template<typename T>
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	void showMap(unordered_map<char, int> umap) {
		for (auto i : umap) {
			cout << i.first << ", " << i.second << endl;
		}
	}

};

int main(int argc, char const *argv[])
{
	string s1 = "cbaebabacd", p1 = "abc";
	string s2 = "abab",	   p2 = "ab";
	Solution solution;

	std::vector<int> res1 = solution.findAnagrams(s1, p1);
	solution.showVec(res1);
	std::vector<int> res2 = solution.findAnagrams(s2, p2);
	solution.showVec(res2);

	return 0;
}
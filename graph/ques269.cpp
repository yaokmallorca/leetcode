#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <algorithm> 
#include <queue>
#include <list>
#include <utility>
#include <set>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	string alienOrder(std::vector<string>& words) {
		set< pair<char, char> > st;
		unordered_set<char> ch;
		vector<int> in(256);
		queue<char> que;
		string res = "";

		for (auto word : words) ch.insert(word.begin(), word.end());
		// add edges
		for (int i = 0; i < words.size() - 1; ++i) {
			/* code */
			int mn = min(words[i].size(), words[i+1].size());
			int j = 0;
			for (; j < mn; ++j) {
				/* code */
				if (words[i][j] != words[i+1][j]) {
					st.insert(make_pair(words[i][j], words[i+1][j]));
					break;
				}
			}
			if (j == mn && words[i].size() > words[i + 1].size()) return "";
		}

		// add in degrees
		for (auto c : st) ++in[c.second];
		for (auto c : ch) {
			if (in[c] == 0) {
				que.push(c);
				res += c;
			}
		} 

		while (!que.empty()) {
			char c = que.front(); que.pop();
			for (auto a : st) {
				if (a.first == c) {
					--in[a.second];
					if (in[a.second] == 0) {
						que.push(a.second);
						res += a.second;
					}
				}
			}
		}
		return res;
	}

	void showSet(unordered_set<char> uset) {
		for (auto s : uset) {
			cout << s << " ";
		}
		cout << endl;
	}

	void showSetPair(set< pair<char, char> > uset_pair) {
		for (auto s : uset_pair) {
			cout << s.first << ", " << s.second << endl;
		}
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[]) {
	std::vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
	// std::vector<string> words = {"z", "x"};
	Solution s;
	// wertf
	cout << s.alienOrder(words) << endl;
	return 0;
}

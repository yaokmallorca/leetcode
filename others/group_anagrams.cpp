#include <iostream>
#include <string>
#include <cstring> // strcmp
#include <vector>
#include <map>
#include <algorithm> // count
#include <set>
#include <queue>
#include <map>
#include <utility> // pair
#include <unordered_map>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<string> > groupAnagrams_own(std::vector<string>& strs) {
		std::vector< std::vector<string> > ret;
		std::vector<bool> flags(strs.size(), false);
		for (int i=0; i<strs.size(); ++i) {
			string str = strs[i];
			std::vector<string> anagrams;
			if (flags[i]) continue;
			else {
				anagrams.push_back(strs[i]);
				flags[i] = true;
			}
			for (int j=i+1; j<strs.size(); ++j) {
				if (isAnagrams(strs[i], strs[j]) && !flags[j]) {
					anagrams.push_back(strs[j]);
					flags[j] = true;
				}
			}
			if (anagrams.size() > 0) {
				ret.push_back(anagrams);
				anagrams.clear();
			}
		}
		return ret;
	}
	
	bool isAnagrams(string str1, string str2) {
		string a = str1;
		string b = str2;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (0 == strcmp(a.c_str(), b.c_str())) {
			return true;
		} else {
			return false;
		}
	}

	void showMap(unordered_map<string, int> maps) {
		for(unordered_map<string, int>::iterator iter=maps.begin(); iter!=maps.end(); ++iter) {
			cout << "key: " << iter->first << ", " << iter->second << endl;\
		}
	}

	std::vector< std::vector<string> > groupAnagrams0(std::vector<string>& strs) {
		std::vector< std::vector<string> > ret;
		unordered_map<string, int> m;
		for (auto str : strs) {
			string t = str;
			sort(t.begin(), t.end());
			if (!m.count(t)) {
				m[t]= ret.size();
				ret.push_back({});
			}
			ret[m[t]].push_back(str);
			showMap(m);
			cout << "<<<<<<<<<<<<<<<<<<" << endl;
		}
		return ret;
	}

	std::vector< std::vector<string> > groupAnagrams(std::vector<string> strs) {
		std::vector< std::vector<string> > res;
		unordered_map<string, int> m;
		for (int i=0; i<strs.size(); ++i) {
			string t = strs[i];
			sort(t.begin(), t.end());
			if (!m.count(t)) {
				m[t] = res.size();
				res.push_back({});
			}
			res[m[t]].push_back(strs[i]);
		}
		return res;
	}

	void showFlags(std::vector<bool> flags) {
		for (auto flag : flags) {
			cout << flag << " ";
		}
		cout << endl;
	}

	void showVec(std::vector< std::vector<string> > strs) {
		for(std::vector< std::vector<string> >::iterator iter = strs.begin(); iter != strs.end(); ++iter) {
			showVec(*iter);
		}
	}

	void showVec(std::vector<string> strs) {
		for (auto str : strs) {
			cout << str.c_str() << " ";
		}
		cout << endl;
	}
};

int main() {
	Solution solution;

	std::vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	solution.showVec(strs);
	std::vector< std::vector<string> > result_anagrams = solution.groupAnagrams(strs);

	solution.showVec(result_anagrams);
	// std::vector< std::vector<string> > group_result = s.groupAnagrams(strs);

}
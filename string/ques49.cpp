#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	std::vector< std::vector<string> > groupAnagrams(std::vector<string>& strs) {
		if (strs.size() <= 1) return {strs};
		std::vector< std::vector<string> > res;
		unordered_map< string, int > umap;
		for (auto str : strs) {
			string tmp_str = str;
			sort(str.begin(), str.end());
			std::vector<string> tmp;
			if (!umap.count(str)) {
				umap[str] = res.size();
				res.push_back({});
			}
			res[umap[str]].push_back(tmp_str);
		}
		return res;
	}



	void showMap(unordered_map<string, int> umap) {
		for (auto it : umap) {
			cout << it.first << ", " << it.second << endl;
		}
	}


	template<typename T>
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num  << " ";
		}
		cout << endl;
	}

	template<typename T> 
	void showVec(std::vector< std::vector<T> > nums) {
		for (auto num : nums) {
			showVec(num);
		}

	}
};

int main(int argc, char const *argv[])
{
	std::vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	cout << count(strs.begin(), strs.end(), "tan") << endl;
	Solution s;

	std::vector< std::vector<string> > res = s.groupAnagrams(strs);
	s.showVec(res);

	return 0;
}
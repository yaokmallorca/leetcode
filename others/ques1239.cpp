#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <map>
#include <utility> // pair
#include <unordered_map>
#include <algorithm> // count


using namespace std;

class Solution
{
public:
	void showVec(std::vector<string> vecs) {
		for (auto str : vecs) {
			cout << str.c_str() << " ";
		}
		cout << endl;
	}

public:
	std::vector<string> maxLength(std::vector<string>& arr) {
		std::vector<string> res;
		res.push_back("");
		// string out;
		for (int i=0; i<arr.size(); ++i) {
			if (isValid(arr[i]) && (0 == count(res.begin(), res.end(), arr[i]))) {
				res.push_back(arr[i]);
			}
			string out = arr[i];
			for (int j=i+1; j<arr.size(); ++j) {
				out += arr[j];
				if (isValid(out) && (0 == count(res.begin(), res.end(), out)))
					res.push_back(out);
			}
		}
		
		return res;
	}

	bool isValid(string str) {
		unordered_map<char, int> umap;
		for (int i=0; i<str.size(); ++i) {
			if (umap.find(str[i]) != umap.end())
				return false;
			else {
				umap[str[i]] = 1;
			}
		}
		return true;
	}


};

int 
main() {
	Solution s;

	std::vector<string> arr = {"un","iq","ue"};
	std::vector<string> results = s.maxLength(arr);
	s.showVec(results);


}

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		int len = strs.size();
		string first = strs[0];
		string ret = "";
		int first_len = strlen(first.c_str());
		// for(int j=1; j<(first_len+1); j++) {
		for(int j=1; j<(first_len+1); j++) {
			string sub = first.substr(0, j);
			int cnt = 0;
			for (int i=1; i<len; i++) {
				string tmp = strs[i];
				size_t found = tmp.find(sub);
				if ((found != string::npos) && (found == 0))
					cnt +=1;
			}
			cout << "cnt " << cnt << ", " << (len-1) << endl;
			if (cnt == (len-1)){
				ret = sub;
			}
		}
		// return ret;
		return (strlen(ret.c_str()) >= 1) ?  ret : "";
	}
};

int main () {
	vector<string> strs;
	strs.push_back("a");
	// strs.push_back("flower");
	// strs.push_back("flower");
	// strs.push_back("car");

	Solution s;
	string ret = s.longestCommonPrefix(strs);
	cout << "result: " << ret.c_str() << endl;



	return 0;
}
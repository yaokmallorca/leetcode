#include <stdlib.h>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	// if the current letter is not the last one, 
	// and the previous one is not lower than the current one
	// res add the current
	// else res substract the current

	int romanToInt(string s) {
		// unordered_map<char, int> umap{{'M', 1000}, {'D', 500}, {'C', 100},
		// 		{'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
		// int res = 0;
		// for (int i = 0; i < s.size(); ++i) {
		// 	if (i == (s.size() - 1) || (umap[s[i+1]] < umap[s[i]]))
		// 		res += umap[s[i]];
		// 	else 
		// 		res -= umap[s[i]];
		// }
        unordered_map<char, int> umap{{'M', 1000}, {'D', 500}, {'C', 100},
				{'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int res = 0;
        for (int i=0; i<s.size(); ++i) {
            if (i == (s.size() - 1) || (umap[s[i+1]] <= umap[s[i]])) {
                res += umap[s[i]];
            } else {
                res -= umap[s[i]];
            }
        }
		return res;
	}
	
};

int main(int argc, char const *argv[])
{
	string str = "III"; // 1994
	Solution s;
	cout << s.romanToInt(str) << endl;
	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string convert1(string s, int numRows) {
		if (s.size() == 0) return s;
		string res = "";
		int n = s.size(), in_val = 2*numRows-2, pos=0;

		// pos = j + 2*R - 2*r
		// R = numRows, r = cur_row, j = str[cur_row][cur_col-1]
		for (int i=0; i<n; i+=in_val) {
			int cur_col = i / numRows;
			string tmp = "";
			for (int r=0; r<numRows; ++r) {
				pos = cur_col + r;
				res += s[pos];
				pos = pos + 2*numRows - 2 - 2*r;

			}
			res += tmp;
		}
		return res;
	}
	

	string convert(string s, int numRows) {
		if (numRows <= 1) return s;
		string res;
		int size = 2 * numRows - 2, n = s.size();
		for (int i = 0; i < numRows; ++i) {
			for (int j = i; j < n; j += size) {
				res += s[j];
				int pos = j + size - 2 * i;
				if (i != 0 && i != numRows - 1 && pos < n) res += s[pos];
			}
		}
		return res; 
	}

};

int main(int argc, char const *argv[])
{
	string str = "PAYPALISHIRING";
	Solution s;
	cout << s.convert(str, 4) << endl;

	return 0;
}
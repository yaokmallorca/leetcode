#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <map>
#include <utility> // pair

using namespace std;

class Solution
{
public:
	int totalNQueens(int n) {
		int res = 0;
		std::vector<int> pos(n, -1);
		queensHelper(pos, 0, res);
		return res;
	}
	int queensHelper(std::vector<int>& pos, int row, int& res) {
		int n = pos.size();
		if (row == n) ++res;
		for (int col=0; col<n; ++col) {
			if (isValid(pos, row, col)) {
				pos[row] = col;
				queensHelper(pos, row+1, res);
				pos[row] = -1;
			}
		}
	}
	bool isValid(std::vector<int>& pos, int row, int col) {
		for (int i=0; i<row; ++i)  {
			if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
				return false;
			}
		}
		return true;
	}
	

};

int main() {
	Solution s;
	int queen_res = s.totalNQueens(5);
	cout << "In total, it has " << queen_res << " solutions." << endl;
}


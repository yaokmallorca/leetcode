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
	std::vector< std::vector<string> >  solveNQueens(int n) {
		std::vector< std::vector<string> > res;
		string queen_row(n, '.');
		std::vector<string> queens(n, queen_row);
		// showVec(queens);
		queensHelper(res, queens, 0);
		return res;
	}
	void queensHelper(std::vector< std::vector<string> >& res, std::vector<string>& queens, int currRow) {
		int n = queens.size();
		if (currRow == n) {
			res.push_back(queens);
			return;
		}
		for (int i=0; i<n; ++i) {
			if (isValid(queens, currRow, i)) {
				queens[currRow][i] = 'Q';
				queensHelper(res, queens, currRow+1);
				queens[currRow][i] = '.';
			}
		} 
	}

	bool isValid(std::vector<string> queens, int row, int col) {
		int n = queens.size();
		// check current row
		for(int i=0; i<n; ++i) {
			if(queens[row][i] == 'Q') return false;
		}

		// check current col
		for(int i=0; i<n; ++i) {
			if(queens[i][col] == 'Q') return false;
		}

		// check top left diagnal
		for(int i=row-1, j=col-1; i>=0&&j>=0; --i,--j) {
			if (queens[i][j] == 'Q') return false;
		}
		// check bottom right diagnal
		for(int i=row-1, j=col+1; i>=0&&j<n; --i,++j) {
			if (queens[i][j] == 'Q') return false;
		}
		return true;
	}

	void showVec(std::vector<string> strs) {
		for (auto str : strs) {
			cout << str.c_str() << " " << endl;
		}
		cout << endl;
	}

	void showVec(std::vector< std::vector<string> > str_arr) {
		for (auto strs : str_arr) {
			showVec(strs);
		}
	}

};

int main() {
	Solution s;
	std::vector< std::vector<string> > queens_res = s.solveNQueens(5); 
	cout << "result size: " << queens_res.size() << endl;
	s.showVec(queens_res);
}
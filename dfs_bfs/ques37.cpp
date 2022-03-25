#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	void solveSudoku(vector<vector<char>>& board) {
		solveDFS(board);
	}

private:
	bool solveDFS(std::vector< std::vector<char> >& board) {
		for (int i = 0; i < 9; ++i) { // rows 
			/* code */
			for (int j = 0; j < 9; ++j) { // cols
				/* code */
				if (board[i][j] != '.') continue;
				for (char num='1'; num<='9'; ++num) {
					if (isValid(board, i, j, num)) {
						board[i][j] = num;
						if (solveDFS(board)) return true;
						board[i][j] = '.';
					}
				}
				return false;
			}
		}
		return true;
	}

	bool isValid(std::vector< std::vector<char> > board, int i, int j, char num) {
		for (int n = 0; n < 9; ++n) {
			/* code */
			// rows
			if (board[n][j] == num && board[n][j] != '.' ) return false;
			// cols
			if (board[i][n] == num && board[i][n] != '.' ) return false;
			// sub grid
			int r = 3 * (i / 3) + n / 3, c = 3 * (j / 3) + n % 3;
			if (board[r][c] == num) return false;
		}
		return true;
	}

};
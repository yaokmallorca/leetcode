#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector< vector<string> > solveNQueens(int n) {
		vector< vector<string> > res;
		vector<string> board(n, string(n, '.'));
		solveNQueensDFS(0, board, res);
		return res;
	}

private:
	void solveNQueensDFS(int curRow, std::vector<string>& board, 
		std::vector< std::vector<string> >& res) {

		if (curRow == n) {
			res.push_back(board);
			return;
		}

		for(int i=0; i<n; ++i) {
			if (isValid(board, curRow, i)) {
				board[curRow][i] = 'Q';
				solveNQueensDFS(curRow+1, board, res);
				board[curRow][i] = '.'
			}
		}

	}

	bool isValid(vector<string>& board, int row, int col) {
		for (int i = 0; i < row; ++i) {
			if (board[i][col] == 'Q') return false;
		}
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
			if (queens[i][j] == 'Q') return false;
		}
		for (int i = row - 1, j = col + 1; i >= 0 && j < queens.size(); --i, ++j) {
			if (queens[i][j] == 'Q') return false;
		}
		return true;

	}


};
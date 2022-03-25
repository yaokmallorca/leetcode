#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int solveNQueens(int n) {
		vector<string> queens(n, string(n, '.'));
		int res = 0;
		solveNQueensDFS(0, queens, res);
		return res;
	}

private:
	void solveNQueensDFS(int curRow, std::vector<string>& board, int& res) {
		int n = board.size();
		if (curRow == n) { ++res;}
		for(int i=0; i<n; ++i) {
			if (isValid(board, curRow, i)) {
				board[curRow][i] = 'Q';
				solveNQueensDFS(curRow+1, board, res);
				board[curRow][i] = '.';
			}
		}

	}

	bool isValid(vector<string>& board, int row, int col) {
		for (int i = 0; i < row; ++i) {
			if (board[i][col] == 'Q') return false;
		}
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
			if (board[i][j] == 'Q') return false;
		}
		for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j) {
			if (board[i][j] == 'Q') return false;
		}
		return true;
	}


};
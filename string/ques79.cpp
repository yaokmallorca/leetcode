#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// DFS
class Solution
{
public:
	bool exist(std::vector< std::vector<char> >& board, string word) {
		if (board.empty() || board[0].empty()) return false;
		int m = board.size(), n = board[0].size();
		std::vector< std::vector<bool> > visited(m, std::vector<bool>(n, false));

		for (int i = 0; i < m; ++i) {
			/* code */
			for (int j = 0; j < n; ++j) {
				/* code */
				if (findWord(board, word, 0, i, j, visited)) return true;
			}
		}
		return false;

	}


	bool findWord(std::vector< std::vector<char> >& board, string& word, int start, 
		int pos_x, int pos_y, std::vector< std::vector<bool> >& visited) {
		if (start == word.size()) return true;
		if (pos_x < 0 || pos_x >= board.size() || pos_y < 0 || pos_y >= board[0].size() 
			|| board[pos_x][pos_y] != word[start] || visited[pos_x][pos_y]) return false; 
		visited[pos_x][pos_y] = true;
		bool res = findWord(board, word, start+1, pos_x-1, pos_y, visited) || 
				   findWord(board, word, start+1, pos_x+1, pos_y, visited) ||
				   findWord(board, word, start+1, pos_x, pos_y-1, visited) ||
				   findWord(board, word, start+1, pos_x, pos_y+1, visited);
		visited[pos_x][pos_y] = false;
		return res;
	}
};

int main(int argc, char const *argv[])
{
	std::vector< std::vector<char> > board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
	string word = "ABCCED";
	Solution s;
	cout << s.exist(board, word) << endl;
	return 0;
}
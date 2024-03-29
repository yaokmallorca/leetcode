#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = grid[0].size(), res = 0;
		vector<vector<bool>> visited(m, vector<bool>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '0' || visited[i][j]) continue;
				numIslandsDFS(grid, visited, i, j);
				++res;
			}
		}
		return res;
	}

	void numIslandsDFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
		if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0' || visited[x][y]) return;
		visited[x][y] = true;
		helper(grid, visited, x - 1, y);
		helper(grid, visited, x + 1, y);
		helper(grid, visited, x, y - 1);
		helper(grid, visited, x, y + 1);
	}

	int numIslandsBFS(std::vector< std::vector<char> >& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = grid[0].size(), res = 0;
		std::vector< std::vector<bool> > visited(m, std::vector<bool>(n, false));

		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				if (grid[i][j] == '0' || visited[i][j]) continue;
				++res;
				queue<int> que()

			}
		}
	}


};
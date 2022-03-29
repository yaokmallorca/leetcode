#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <algorithm> 
#include <queue>
#include <list>

using namespace std;

class Solution
{
public:
	int numIslands(std::vector< std::vector<int> >& grids) {
		if (grids.empty() || grids[0].empty()) return 0;
		int m = grids.size(), n = grids[0].size(), res = 0;
		std::vector< std::vector<bool> > visited(m, std::vector<bool>(n, false));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grids[i][j] == 0 || visited[i][j]) continue;
				numIslandsDFS(grids, visited, i, j);
				++res;
			}
		}
		return res;
	}

	void numIslandsDFS(std::vector< std::vector<int> >& grids, 
		std::vector< std::vector<bool> >& visited, int i, int j) {
		if (i < 0 || i >= grids.size() || j < 0 || j >= grids[0].size() 
			|| grids[i][j] == 0 || visited[i][j] ) return;
		visited[i][j] = true;
		numIslandsDFS(grids, visited, i-1, j);
		numIslandsDFS(grids, visited, i+1, j);
		numIslandsDFS(grids, visited, i, j-1);
		numIslandsDFS(grids, visited, i, j+1);
	}

	int numIslandsBFS(std::vector< std::vector<int> >& grids) {
		if (grids.empty() || grids[0].empty()) return 0;
		int m = grids.size(), n = grids[0].size(), res = 0;
		std::vector< std::vector<bool> > visited(m, std::vector<bool>(n, false));
		std::vector< std::vector<int> > dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		queue< std::vector<int> > que;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grids[i][j] == 0 || visited[i][j]) continue;
				que.push({i, j});
				visited[i][j] = true;
				while (!que.empty()) {
					std::vector<int> pos = que.front(); que.pop();
					for (auto dir : dirs) {
						int x = pos[0] + dir[0], y = pos[1] + dir[1];
						if (x>=0 && x<m && y>=0 && y<n && !visited[x][y] && grids[x][y] == 1) {
							visited[x][y] = 1;
							que.push({x, y});
						}
					}
				}
				res++;
			}
		}
		return res;
	}

};

int main(int argc, char const *argv[])
{
	std::vector< std::vector<int> > grids = {{1, 1, 0, 0, 0},
											 {1, 1, 0, 0, 0},
											 {0, 0, 1, 0, 0},
											 {0, 0 ,0, 1, 1}};

	Solution s;
	cout << "num of islands: " << s.numIslandsBFS(grids) << endl;
	return 0;
}
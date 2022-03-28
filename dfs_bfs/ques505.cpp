#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
using TP = pair<int, pair<int, int> >; // distance, x, y

class Solution
{
public:
	// Dijkstra Algorithm: non-fixed edge weight graph, shortest distance 
	int shortestDistanceBFS(vector<vector<int>>& maze, vector<int>& start, 
		vector<int>& destination) {
		int m = maze.size();
		int n = maze[0].size();
		auto dirs = std::vector< pair<int, int> >{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		auto visited = std::vector< std::vector<int> >(m, std::vector<int>(n, 0));
		priority_queue< TP, std::vector<TP>, less<> > pq; 

		pq.push({0, {start[0], start[1]}});
		while (!pq.empty()) {
			int dist = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();

			if (x == destination[0] && y == destination[1]) return dist;
			if (visited[x][y]) continue;
			visited[x][y] = 1;
			for (auto dir : dirs) {
				int i = x, j = y, step = 0;
				while (i+dir.first>=0 && i+dir.first<m && j+dir.second>=0 
					&& j+dir.second<n && maze[i+dir.first][j+dir.second]==0) {
					++step;
					i += dir.first; j += dir.second;
				}
				if (visited[i][j]) continue;
				pq.push({dist+step, {i, j}});
			}
		}
		return -1;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> start = {0, 4}, end =  {4, 4}; // {4, 4}; 
	std::vector< std::vector<int> > maze = {{0, 0, 1, 0, 0},
											{0, 0, 0, 0, 0},
											{0, 0, 0, 1, 0},
											{1, 1, 0, 1, 1},
											{0, 0, 0, 0, 0}};

	Solution s;
	cout << "shortest distance: " << s.shortestDistanceBFS(maze, start, end) << endl;
	// s.showVec(maze);


	return 0;
}
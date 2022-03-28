#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution
{
public:
	bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		return mazeDFS(maze, start[0], start[1], destination[0], destination[1]);
	}
	
	bool mazeDFS(std::vector< std::vector<int> >& maze, 
		int start_x, int start_y, int end_x, int end_y) {
		if (start_x == end_x && start_y == end_y) return true;
		bool res = false;
		int m = maze.size(), n = maze[0].size();
		maze[start_x][start_y] = -1;
		for (auto dir : dirs) {
			int x = start_x, y = start_y;
			while (x>=0 && x<m && y>=0 && y<n && maze[x][y]!=1) {
				x += dir[0]; y += dir[1];
			}
			x -= dir[0]; y -= dir[1];
			if (maze[x][y] != -1) { 
				res |= mazeDFS(maze, x, y, end_x, end_y);
			}
		}
		return res;
	}

	bool hasPathBFS(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
		int m = maze.size(), n = maze[0].size();
		std::vector< std::vector<bool> > visited(m, std::vector<bool>(n, false));
		queue< pair<int, int> > q;
		q.push(make_pair(start[0], start[1]));
		visited[start[0]][start[1]] = true;
		while (!q.empty()) {
			auto t = q.front(); q.pop();
			if (t.first == dest[0] && t.second == dest[1]) return true;
			for (auto dir : dirs) {
				int x = t.first, y = t.second;
				while (x >=0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
					x += dir[0]; y += dir[1];
				}
				x -= dir[0]; y -= dir[1];
				if (!visited[x][y]) {
					visited[x][y] = true;
					q.push( {x, y} );
				}
			}
		}
		return false;
	}

	template<typename T>
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	template<typename T>
	void showVec(std::vector< std::vector<T> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}

private:
	// left, right, up, down
	std::vector< std::vector<int> > dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
};

int main(int argc, char const *argv[])
{
	std::vector<int> start = {0, 4}, end =  {3, 2}; // {4, 4}; 
	std::vector< std::vector<int> > maze = {{0, 0, 1, 0, 0},
											{0, 0, 0, 0, 0},
											{0, 0, 0, 1, 0},
											{1, 1, 0, 1, 1},
											{0, 0, 0, 0, 0}};

	Solution s;
	cout << "has path: " << s.hasPathBFS(maze, start, end) << endl;
	// s.showVec(maze);


	return 0;
}
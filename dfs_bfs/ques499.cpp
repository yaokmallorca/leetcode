#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <tuple>
#include <climits>

using namespace std;
// using TP = pair<int, pair<string, std::vector<int> > >;
using TP = tuple<int, string, int, int>;

class Solution
{
public:
	string findShortestWay(std::vector< std::vector<int> >& maze, 
		std::vector<int> start, std::vector<int> dst) {
		int m = maze.size(), n = maze[0].size();
		auto visited = std::vector< std::vector<int> >(m, std::vector<int>(n, 0));
		auto dirs = std::vector< pair<int, int> >{{1,0},{0,-1},{0,1},{-1,0}};  // d,l,r,u
		auto step_str = std::vector<string>{"d", "l", "r", "u"};
		// dist, path, x, y
		priority_queue< TP, std::vector<TP>, greater<> > pq;
		// pq.push({0, {"", {start[0], start[1]}}});
		pq.push({0, "", start[0], start[1]});
		string ret_path = "";

		while (!pq.empty()) {
			auto [d, path, x, y] = pq.top();
			pq.pop();

			if (x == dst[0] && y == dst[1]) {
				ret_path = path;
				break;
			}
			if (visited[x][y]) continue;
			visited[x][y] = 1; 
			for (int k = 0; k < dirs.size(); ++k) {
				int i = x, j = y, step = 0;
				while (i+dirs[k].first>=0 && i+dirs[k].first<m && j+dirs[k].second>=0 
					&& j+dirs[k].second<n && maze[i+dirs[k].first][j+dirs[k].second]==0) {
					++step;
					i += dirs[k].first; j += dirs[k].second;
				}
				if (visited[i][j]) continue;

				char ch = '0' + k;
				pq.push({d+step, path+ch, i, j});
			}
		}
		string ret = "";
		if (ret_path.size() == 0)
			return "impossible";
		else {
			for (int i = 0; i < ret_path.size(); ++i) {
				int s = static_cast<int>(ret_path[i] - '0');
				ret += step_str[s];
			}
		}
		return ret;
	}
};

int main(int argc, char const *argv[]) {
	std::vector<int> start = {0, 4}, end =  {4, 4}; // {4, 4}; 
	std::vector< std::vector<int> > maze = {{0, 0, 1, 0, 0},
											{0, 0, 0, 0, 0},
											{0, 0, 0, 1, 0},
											{1, 1, 0, 1, 1},
											{0, 0, 0, 0, 0}};

	Solution s;
	cout << s.findShortestWay(maze, start, end) << endl;
	// cout << path << endl;
	return 0;
}
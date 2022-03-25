#include <iostream>
#include <string>
#include <cstring> // strcmp
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <map>
#include <climits>
#include <iterator> // iterator
#include <algorithm> // reverse
#include <utility> // pair

using namespace std;

const int INF = 100000000;


/*
BFS 
1，将起点推入队列中；
2，将起点标识为已走过；
while（队列非空）{
  3，取队列首节点vt，并从队列中弹出；
  4，探索上面取出得节点的周围是否有没走过的节点vf，如果有将所有能走的vf的parents指向vt，并将vf加入队列
    （如果vf等于终点，说明探索完成，退出循环）。
}
如果队列为空自然跳出，说明无路可达终点。

DFS
1，栈初始化
2，获得起点，将起点标识为已走过，将起点入栈
while（栈非空）{
  取栈顶元素vt
  如果vt周围有为走过的节点vf，则：
      将vf改为已走
      vf入栈
  没有能走的节点，vt出栈
}
*/



class Solution
{
public:
	template <typename T>
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " " ;
		}
		cout << endl;
	}

	template<typename T>
	void showVec(std::vector< std::vector<T> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}

	template<typename T>
	void showPath(queue< pair<T, T> > path) {
		while (!path.empty()) {
			pair<T, T> pos = path.front();
			path.pop();
			cout << "(" << pos.first << ", " << pos.second << ")" << endl;
		}
	}

	/*
	BFS 
	1，将起点推入队列中；
	2，将起点标识为已走过；
	while（队列非空）{
	  3，取队列首节点vt，并从队列中弹出；
	  4，探索上面取出得节点的周围是否有没走过的节点vf，如果有将所有能走的vf的parents指向vt，并将vf加入队列
	    （如果vf等于终点，说明探索完成，退出循环）。
	}
	如果队列为空自然跳出，说明无路可达终点。
	*/
	template<typename T>
	int BFS(std::vector< std::vector<T> > arr, int sx, int sy, int gx, int gy, T wall){
		int h = arr.size(), w = arr[0].size();
		std::queue< pair<int, int> > path;
		path.push({sx, sy});
		std::vector< std::vector<int> > pos_flag(arr.size(), std::vector<int>(arr[0].size(), 0));
		pos_flag[0][0] = 0;
		int i=0, j=0;
		std::vector<int> step_x = {1, 0, -1, 0};
		std::vector<int> step_y = {0, 1, 0, -1};

		while(!path.empty()) {
			auto pos = path.front();
			path.pop();
			if (arr[pos.first][pos.second] == 'G') break;
			for (int n=0; n<step_x.size(); ++n) {
				int nx = pos.first + step_x[n];
				int ny = pos.second + step_y[n];
				if (nx>=0 && nx<h && ny>=0 && ny<w && arr[nx][ny]!=wall && pos_flag[nx][ny]==0) {
					pos_flag[nx][ny] = pos_flag[pos.first][pos.second] + 1;
					path.push({nx, ny});
				}
			}
		}
		return pos_flag[gx][gy];
	}

	template<typename T>
	int DFS(std::vector< std::vector<T> > arr, int sx, int sy, int gx, int gy, T wall) {
		int res = 0;

		return res;
	}

	template<typename T>
	void helperDFS(std::vector< std::vector<T> > arr, int x, int y, int path, int& res, T wall, T end) {
		int m = arr.size(), n = arr[0].size();
		if (x>=m || y>=n) return;
		if (arr[x][y] == end) res = path<res ? path : res; return;
		std::vector<int> step_x = {1, 0, -1, 0};
		std::vector<int> step_y = {0, 1, 0, -1};
		for(int n=0; n<step_x.size(); ++i) {
			int nx = x + step_x[n];
			int ny = y + step_y[n];
			if (nx>=0 && nx<m && ny>=0 && ny<n && arr[nx][ny]!=wall) {
				path += 1;
			}
		}
	}

};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector< std::vector<char> > arr1;
	arr1.push_back({'#','S','#','#','#','#','#','#','.','#'});
	arr1.push_back({'.','.','.','.','.','.','#','.','.','#'});
	arr1.push_back({'.','#','.','#','#','.','#','#','.','#'});
	arr1.push_back({'.','#','.','.','.','.','.','.','.','.'});
	arr1.push_back({'#','#','.','#','#','.','#','#','#','#'});
	arr1.push_back({'.','.','.','.','#','.','.','.','.','#'});
	arr1.push_back({'.','#','#','#','#','#','#','#','.','#'});
	arr1.push_back({'.','.','.','.','#','.','.','.','.','.'});
	arr1.push_back({'.','#','#','#','#','.','#','#','#','#'});
	arr1.push_back({'.','.','.','.','#','.','.','.','G','#'});

	std::vector< std::vector<int> > arr2; 
	arr2.push_back({1,2,1,0,1});
	arr2.push_back({0,0,0,0,1});
	arr2.push_back({1,1,1,0,1});
	arr2.push_back({1,1,0,0,1});
	arr2.push_back({1,0,0,2,1});

	std::vector< std::vector<int> > arr3;
	arr3.push_back({0,0,1,0,1});
	arr3.push_back({0,1,1,1,0});
	arr3.push_back({0,0,0,0,0});
	arr3.push_back({0,1,1,1,0});
	arr3.push_back({0,0,0,1,0});

	s.showVec(arr1);
	int shortest_path1 = s.BFS(arr1, 0, 1, 9, 8, '#');
	cout << "BFS: " << shortest_path1 << endl;

	s.showVec(arr2);
	int shortest_path2 = s.BFS(arr2, 0, 1, 4, 3, 1);
	cout << "BFS: " << shortest_path2 << endl;

	s.showVec(arr3);
	int shortest_path3 = s.BFS(arr3, 0, 0, 4, 4, 1);
	cout << "BFS: " << shortest_path3 << endl;

	return 0;
}
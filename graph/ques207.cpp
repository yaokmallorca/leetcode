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
	bool canFinish(int numCourses, std::vector< std::vector<int> >& prerequisites) {
		std::vector< std::vector<int> > adj(numCourses, std::vector<int>());
		std::vector<int> in_degrees(numCourses, 0);
		int count = 0;
		for (auto pre : prerequisites) {
			in_degrees[pre[1]]++;
			adj[pre[0]].push_back(pre[1]);
		}

		std::vector<int> visited(numCourses);
		queue<int> que;
		for (int i = 0; i < numCourses; ++i) {
			/* code */
			if (in_degrees[i] == 0) {
				que.push(i); 
				count++;
			}
		}
		while(!que.empty()) {
			/* code */
			int cur = que.front(); que.pop();
			visited[cur] = 1;
			for(auto nxt : adj[cur]) {
				--in_degrees[nxt];
				if (in_degrees[nxt] == 0) {
					que.push(nxt); ++count;
				}
			}
		}
		return count == numCourses;
	}
 
	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	/* 
	-1: occupied  -- has circle
	 0: don't visited
	 1: visited 
	*/
	bool canFinish2(int numCourses, 
		std::vector< std::vector<int> >& prerequisites) {
		std::vector<int> visited(numCourses, 0);
		std::vector< std::vector<int> > adj(numCourses, std::vector<int>());
		for (auto p : prerequisites) {
			adj[p[0]].push_back(p[1]);
		}

		for (int i = 0; i < numCourses; ++i) {
			/* code */
			if (canFinishDFS(i, visited, adj) == false) return false; 
		}
		return true;
	}

	bool canFinishDFS(int cur, std::vector<int>& visited,
		std::vector< std::vector<int> > adj) {
		if (visited[cur] == 1) return true;
		if (visited[cur] == -1) return false;

		visited[cur] = -1;
		for (auto nxt : adj[cur]) {
			bool finish = canFinishDFS(nxt, visited, adj);
			if (!finish) return false; 
		}
		visited[cur] = 1;
		return true;
	}
};

int main(int argc, char const *argv[])
{
	std::vector< std::vector<int> > prerequisites = {{0, 1}}; // {{1, 0}, {0, 1}};
	Solution s;
	int numCourses = 2;
	cout << s.canFinish2(numCourses, prerequisites) << endl;

	return 0;
}
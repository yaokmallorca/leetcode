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
	// topological sort
	std::vector<int> findMinHeightTrees1(int n, std::vector< std::vector<int> >& edges) {
		std::vector< std::vector<int> > adj(n, std::vector<int>());
		std::vector<int> degrees(n, 0); 
		std::vector<int> ret;
		queue<int> que;

		for (auto edge : edges) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]);
			++degrees[edge[0]]; ++degrees[edge[1]];
		}

		for (int i = 0; i < degrees.size(); ++i) {
			/* code */
			if (degrees[i] == 1) que.push(i);
		}

		int count = 0;
		std::vector<int> visited(n);
		while (!que.empty()) {
			int len = que.size();
			// for (int i = 0; i < len; ++i) {
				/* code */
				int cur = que.front(); que.pop();
				++count;
				visited[cur] = 1;
				for (auto nxt : adj[cur]) {
					--degrees[nxt];
					if (degrees[nxt] == 1) {
						que.push(nxt);
					}
				}
			// }
			if (count >= n-2) break;
		}
		while (!que.empty()) {
			int node = que.front(); que.pop();
			ret.push_back(node);
		}
		return ret;
	}

	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	int n = 6;
	std::vector< std::vector<int> > edges = {{0, 3}, {1, 3}, 
											 {2, 3}, {4, 3},
											 {5, 4}};
	Solution s;
	std::vector<int> ret = s.findMinHeightTrees(n, edges);
	s.showVec(ret);
	return 0;
}
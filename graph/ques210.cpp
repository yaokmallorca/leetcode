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
	std::vector<int> findOrder(int numCourses, std::vector< std::vector<int> >& prerequisites) {
		std::vector<int> res;
		std::vector< std::vector<int> > graph(numCourses);
		std::vector<int> in_degrees(numCourses);
		queue<int> que;

		for (auto pre : prerequisites) {
			graph[pre[1]].push_back(pre[0]);
			in_degrees[pre[0]]++;
		}

		for (int i = 0; i < numCourses; ++i) {
			/* code */
			if (in_degrees[i] == 0) que.push(i);
		}

		while (!que.empty()) {
			int len = que.size();
			for (int i = 0; i < len; ++i) {
				int t = que.front(); que.pop();
				res.push_back(t);
				for (auto nxt : graph[t]) {
					--in_degrees[nxt];
					if (in_degrees[nxt] == 0) que.push(nxt);
				}
			}
		}
		if (res.size() != numCourses) res.clear();
		return res;
	}
	
	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[]) {
	int numCourses = 4;
	std::vector< std::vector<int> > prerequisites = { {1, 0}, {2, 0}, {3, 1}, {3, 2} };
	Solution s;
	std::vector<int> res = s.findOrder(numCourses, prerequisites);
	s.showVec(res); 
	return 0;
}


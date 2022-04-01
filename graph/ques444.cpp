#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <algorithm> 
#include <queue>
#include <list>
#include <utility>
#include <set>
#include <unordered_set>

using namespace std;

class Solution
{
public:

	// topological sort
	bool sequenceReconstruction(vector<int>& dst, vector< vector<int> >& seqs) {
		int n = dst.size();
		auto adj = std::vector< std::vector<int> >(n+1, std::vector<int>());
		auto in_degree = std::vector<int>(n+1, 0);

		for (auto seq : seqs) {
			for (int i = 1; i < seq.size(); ++i) {
				/* code */
				in_degree[seq[i]]++; 
				adj[seq[i-1]].push_back(seq[i]);
			}
		}

		queue<int> que;
		for (int i = 1; i <= n; ++i) {
			if (in_degree[i] == 0) que.push(i);
		}

		int cnt = 0;
		while(!que.empty()) {
			if (que.size()>1)
				return false;

			auto val = que.front(); que.pop();
			if (val != dst[cnt]) return false;
			++cnt;
			for (auto node : adj[val]) {
				in_degree[node]--;
				if (in_degree[node] == 0) {
					que.push(node);
				}
			}
		}
		if (cnt != dst.size()) return false;
		return true;;
	}

};

int main(int argc, char const *argv[])
{
	std::vector< std::vector<int> > nums1 = {{1,2}, {1,3}};
	std::vector< std::vector<int> > nums2 = {{1,2}, {1,3}, {2,3}};
	std::vector< std::vector<int> > nums3 = {{5,2,6,3},{4,1,5,2}};
	std::vector<int> dst1 = {1,2,3};
	std::vector<int> dst2 = {4,1,5,2,6,3};


	Solution s;
	cout << s.sequenceReconstruction(dst1, nums1) << endl;
	cout << s.sequenceReconstruction(dst1, nums2) << endl;
	cout << s.sequenceReconstruction(dst2, nums3) << endl;
	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	// BFS ？？
	int findKthNumber(int n, int k) {
		long cur = 1;
		k = k-1;

		while(k > 0) {
			long node_num = getTreeNodesNum(n, cur);
			cout << "node num: " << node_num << ", cur" << cur << endl;
			if (k >= node_num) {  // target is not in this subtree (cur is root)
				k -= node_num;
				cur++;
			} else {  // target is in this subtree
				cur *= 10;
				k  = k -1;  // count the node cur
			}
		}
		return (int)cur;
	}

private:
	int getTreeNodesNum(int n, long cur) {
		long long first = cur;
		long long next = cur + 1;
		long long totalNodes = 0;

		while (first <= n) {
			cout << "first: " << first << ", n: " << n << endl;
			totalNodes += min((long long)n-first+1,    // in the current tree
							  next-first);  // in the subtree
			first *= 10;
			next *= 10;
		}
		return (int)totalNodes;
	}
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int n = 13, k = 2;
	cout << "find :" << solution.findKthNumber(n, k) << endl;


	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <climits>

using namespace std;

class Graph {
public:
	int v;
	// list<string>* adj;
	unordered_map<string, list<string> > adj;

public:
	Graph(int num_vertice) {
		v = num_vertice;
		// adj = new list<string>[v];
	}

	void addEdge(string v, string w) {
		adj[v].push_back(w);
	}

	void DFS(string start, std::vector<string> word_dict) {
		unordered_map<string, bool> visited;
		visited[start] = false;
		for(auto word : word_dict) {
			visited[word] = false;
		}

		if (!visited[start]) {
			DFSUtils(start, visited);
		}
	}

	void DFSUtils(string s, unordered_map<string, bool>& visited) {
		if (visited[s]) return;
		cout << s << " ";
		visited[s] = true;
		list<string>::iterator it;
		for (it = adj[s].begin(); it != adj[s].end(); ++it) {
			if (!visited[*it]) {
				DFSUtils(*it, visited);
			}
		}
	}

	int BFS(string start, string end, std::vector<string> word_dict) {
		unordered_map<string, bool> visited;
		int ret = 0;
		visited[start] = false;
		for(auto word : word_dict) {
			visited[word] = false;
		}

		queue<string> que;
		que.push(start);
		visited[start] = true;
		list<string>::iterator it;
		while (!que.empty()) {
			string str = que.front(); que.pop();
			cout << str << " ";
			for (it = adj[str].begin(); it != adj[str].end(); ++it) {
				if (!visited[*it]) {
					if (*it == end) {
						++ret; return ret;
					}
					que.push(*it); ++ret;
					visited[*it] = true;
				}
			}
		}
		return ret;
	}
};

class Solution
{
public:

	int WordLadder(string start, string end, std::vector<string> word_dict) {
		int n = word_dict.size();
		int min_dist = INT_MAX;
		Graph graph(n+1);
		for (int i = 0; i < n; ++i) {
			/* code */
			if (isEdge(start, word_dict[i])) {
				graph.addEdge(start, word_dict[i]);
			}
		}
		for (int i = 0; i < n; ++i) {
			for(int j = i+1; j < n; ++j) {
				if (isEdge(word_dict[i], word_dict[j])) {
					graph.addEdge(word_dict[i], word_dict[j]);
				}
			}
		}
		return graph.BFS(start, end, word_dict);
	}

	bool isEdge(string a, string b) {
		if (a.size() != b.size()) return false;
		int n = a.size(), i = 0, cnt = 0;
		while (i < n) {
			if (a[i] != b[i]) ++cnt;
			if (cnt > 1) return false;
			++i;
		}
		return true;
	}
};



int main(int argc, char const *argv[])
{
	std::vector<string> word_dict = {"hot", "dot", "dog", "log", "cog"};
	// Graph graph;
	Solution solution;
	// (string start, string end, std::vector<string> word_dict) 
	int res = solution.WordLadder("hit", "cog", word_dict);
	cout << "min path: " << res << endl;




	return 0;
}
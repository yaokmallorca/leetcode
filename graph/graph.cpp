#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
#include <algorithm> 
#include <queue>
#include <list>

using namespace std;

class Graph {
public:
	int v; // no of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
public:
	Graph(int );
	void addEdge(int , int);
	void BFS(int);
	void DFS(int);
	void DFS_traversal(int);
	void DFS_utils(int, std::vector<bool>&);
};

Graph::Graph(int vertices) {
	v = vertices;
	adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::DFS_traversal(int n) {
	std::vector<bool> visited(v, false);
	stack<int> st;
	visited[n] = true;
	st.push(n);

	list<int>::iterator it;
	while (!st.empty()) {
		n = st.top();
		cout << n << " ";
		st.pop();
		for(it = adj[n].begin(); it != adj[n].end(); it++) {
			if(!visited[*it]) {
				visited[*it] = true;
				st.push(*it);
			}
		}
	}
}

void Graph::DFS(int n) {
	std::vector<bool> visited(v, false);
	if (!visited[n])
		DFS_utils(n, visited);
}

void Graph::DFS_utils(int n, std::vector<bool>& visited) {
	if (visited[n]) return;
	cout << n << " ";
	visited[n] = true;
	list<int>::iterator it;
	for (it = adj[n].begin(); it != adj[n].end(); it++) {
		if (!visited[*it])
			DFS_utils(*it, visited);
	}
}

void Graph::BFS(int n)
{
	std::vector<bool> visited(v, false);
	queue<int> q;

	// mark current node as visited and enque it
	visited[n] = true;
	q.push(n);

	list<int> :: iterator it;

	while(!q.empty()) {
		int s = q.front();
		cout<<s<<" ";
		q.pop();
		for(it = adj[s].begin(); it!=adj[s].end(); it++) {
			if(!visited[*it])
			{
				visited[*it] = true;
				q.push(*it);
			}
		}

	}
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
 
	cout << "Following is Breadth First Traversal "
		 << "(starting from vertex 2) \n";
	g.BFS(2);
	cout<<endl;

	cout << "Following is Depth First Traversal "
		 << "(starting from vertex 2) \n";
	g.DFS(2);
	cout<<endl;

	// g.DFS_traversal(2);
	// cout<<endl;
 
	return 0;
}
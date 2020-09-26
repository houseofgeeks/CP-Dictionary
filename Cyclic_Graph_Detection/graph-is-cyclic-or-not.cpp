/* Program for checking whether graph is cyclic or not. */

#include<bits/stdc++.h>
using namespace std;

/* Function for doing DFS of the graph. */
void dfs(vector<int>g[], int S, vector<int> &color, int &flag)
{
	/* color 1 represents the processing node. */
	color[S] = 1;

	for (auto w : g[S])
	{
		/* Checking if graph contains cycle. */
		if (color[w] == 1) flag = 1;

		/* color 0 represents the unvisited node. */
		else if (color[w] == 0) dfs(g, w, color, flag);
	}

	/* color 2 represents the processed node. */
	color[S] = 2;
}


int main()
{
	/* n and m are denoting no. of nodes and edges repectively. */
	int n, m;
	cin >> n >> m;

	/* Adjacency list to store the graph. */
	vector<int> adj[n];

	for (int i = 0; i < m; i++)
	{
		/* Starting node and ending node. */
		int a, b;
		cin >> a >> b;

		/* Adding directed path. */
		adj[a - 1].push_back(b - 1);
	}

	/*Vector for storing color of each node initially set to 0. */
	vector<int> color(n, 0);

	int source_node = 0, flag = 0;

	for (int i = 0; i < n; i++)
	{
		if (color[i] == 0) dfs(adj, source_node, color, flag);
	}

	if (flag == 1) cout << "Graph contains cycle." << endl;
	else cout << "Graph does not contain any cycle." << endl;

	return 0;
}



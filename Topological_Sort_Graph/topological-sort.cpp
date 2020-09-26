/* Program for printing the topological sorted array of a unweighted directed graph. */

#include<bits/stdc++.h>
using namespace std;

/* Function for doing DFS of the graph. */
void dfs(vector<int>g[], int S, vector<int> &color, vector<int> &ts, int &flag)
{
	/* color 1 represents the processing node. */
	color[S] = 1;

	for (auto w : g[S])
	{
		/* Checking if graph contains cycle. */
		if (color[w] == 1) flag = 1;

		/* color 0 represents the unvisited node. */
		else if (color[w] == 0) dfs(g, w, color, ts, flag);
	}
	ts.push_back(S);

	/* color 2 represents the processed node. */
	color[S] = 2;
}


/* Function for doing topological sort. */
vector<int> topo_Sort(int V, vector<int> adj[], int &flag)
{
	/* Vectors for color initially set to 0 for each node
	and a temporary ts vector to store the topological sorted array. */
	vector<int> color(V, 0), ts;

	for (int i = 0; i < V; i++)
	{
		/* If node is unvisited. */
		if (color[i] == 0) dfs(adj, i, color, ts, flag);
	}

	/* Topological sorted array stored in reverse order. */
	reverse(ts.begin(), ts.end());
	return ts;
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

	int flag = 0;
	vector<int> Topo = topo_Sort(n, adj, flag);

	if (flag == 1) cout << "Graph Contains cycle and topological sorting cannot be done." << endl;
	else
	{
		/*Printing the sorted array of nodes. */
		for (int i = 0; i < n; i++)
		{
			cout << Topo[i] + 1 << " ";
		}
		cout << endl;
	}

	return 0;
}



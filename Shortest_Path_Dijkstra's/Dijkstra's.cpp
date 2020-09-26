/* Program for printing the shortest path between source node and end node. */

#include<bits/stdc++.h>
using namespace std;

/* Main Function. */
int main()
{
	/* n and m are denoting no. of nodes and edges repectively. */
	int n, m;
	cin >> n >> m;

	/* Adjacency list to store the graph and the pair
	storing as ending node and weight of te path. */
	vector<pair<int, int>> adj[n];

	/* Vector to store the parent of each node */
	vector<int> par(n, -1);

	for (int i = 0; i < m; i++)
	{
		/* Starting node, ending node and weight of the path. */
		int a, b, w;
		cin >> a >> b >> w;

		/* Adding undirected path. */
		adj[a - 1].push_back(make_pair(b - 1, w));
		adj[b - 1].push_back(make_pair(a - 1, w));
	}

	/* Printing the adjacency list. */
	// for (int i = 0; i < n; i++)
	// {
	// 	for (auto j : adj[i])
	// 	{
	// 		cout << i + 1 << " " << j.first + 1 << " " << j.second << endl;
	// 	}
	// }

	/* Vector for storing the distance of each node and visited node. */
	vector<int> dis(n, INT_MAX);
	vector<int> vis(n, 0);

	/* Min heap priority queue to store the -ve of distance
		(to give priority to minimum distance) and the node. */
	priority_queue<pair<int, int>> q; //dis node

	/* Source node from which we have to start. */
	int source_node = 0;

	/*Since distance of source node is 0. */
	dis[source_node] = 0;
	q.push({0, source_node});

	/* Traversing till the queue becomes empty. */
	while (!q.empty())
	{
		int a = q.top().second;
		q.pop();

		/* If alredy visited then no need to process this node. */
		if (vis[a]) continue;
		vis[a] = 1;

		for (auto u : adj[a])
		{
			int b = u.first, w = u.second;

			/* Checking if the weight is less than the current weight. */
			if (dis[a] + w < dis[b])
			{
				par[b] = a;
				dis[b] = dis[a] + w;

				/* Pushing the node and distance as this can reduce weight further. */
				q.push({ -dis[b], b});
			}
		}
	}

	/* For printing the distance of node from the source node. */
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << dis[i] << " ";
	// }
	// cout << endl;


	/* For printing the parent node. */
	// for (int i = 0; i < par.size(); ++i)
	// {
	// 	cout << par[i] << " ";
	// }
	// cout << endl;

	/* path vector to store the shortest path. */
	vector<int> path;

	/* To check is path exists or not. */
	if (dis[n - 1] == INT_MAX) cout << -1 << endl;
	else
	{
		int x = n - 1;
		path.push_back(x + 1);

		/* Finding the nodes in the path by traversing each node parent wise. */
		while (x != -1)
		{
			path.push_back(par[x] + 1);
			x = par[x];
		}

		/* Reversing the path as currently we have path in reverse order. */
		reverse(path.begin(), path.end());

	}


	/* Printing the path from source node to the end node. */
	for (int i = 1; i < path.size(); i++)
	{
		cout << path[i] << " ";
	}
	cout << endl;

	return 0;
}


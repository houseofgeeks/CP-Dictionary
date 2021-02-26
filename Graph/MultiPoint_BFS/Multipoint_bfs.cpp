#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int dist[1000006];// Array to store the shortest distance of each node from any source.
void multipoint_bfs(vector<vector<int> > &adj, vector<int> source, int n)
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INT_MAX;
	}
	queue<int> q;
	vector<bool> vis(n + 1, false);
	for (int i = 0; i < source.size(); i++)
	{
		dist[source[i]] = 0;
		q.push(source[i]);
		vis[source[i]] = true;
	}
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (int i = 0; i < adj[a].size(); i++)
		{
			if (!vis[adj[a][i]])
			{
				q.push(adj[a][i]);
				dist[adj[a][i]] = min(dist[adj[a][i]], dist[a] + 1);
				vis[adj[a][i]] = true;
			}
		}
	}

}

int main()
{
	int n , m; //n= no. of vertices , m=no. of edges
	cin >> n >> m;
	vector<vector<int> > adj(n + 1); // 1 based indexing
	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x); // creating bidirectional edge
	}

	vector<int> source;// vector to store set of source vetices.

	// Enter the source vertices.
	int no_of_sources;
	cin >> no_of_sources;
	for (int i = 0; i < no_of_sources; i++)
	{
		int x;
		cin >> x;
		source.pb(x);
	}

	multipoint_bfs(adj, source, n);
	cout << "The Shortest distance for each vertex from any of the source is:";
	for (int i = 1; i <= n; i++)
	{
		cout << dist[i] << " ";
	}

}
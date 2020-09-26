#include<bits/stdc++.h>

using namespace std;

const int N=1E5 +5; //Assumed size of graph

vector<int> adj[N];
int vis[N]={0};
int color[N]={0};
 // checking graph is bipartite or not using DFS
bool isBipartite(int v)
{
	for(int u:adj[v])
	{
		if(vis[u]==0) // if vertex is unvisited
		{
			vis[u]=1;
			color[u]=1-color[v]; // since assigning color 0 or 1 to each vertex
			
			if(!isBipartite(u))
				return false;
		}
		else if(color[u]==color[v]) // if a both the vertex of an edge are of same color then return false
			return false;
	}
	return true;
}


int main()
{
	int vertices , edges , x, y;
	cin>>vertices >>edges;
	
	for(int i=0;i<edges;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	color[0]=0; // Assuming 0 as source vertex
	if(isBipartite(0))
		cout<<"Graph is Bipartite.";
	else
		cout<<"Graph is not Bipartite.";
		
	return 0;
	
}

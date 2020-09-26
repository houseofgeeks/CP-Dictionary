
#include <bits/stdc++.h>

using namespace std;

//assumed size of the graph
const int N = 1e5 + 1;

vector<int> adj[N]; // for storing the edges in an adjacency list

int vis[N]={0}; // array for marking the nodes which are already visited

void dfs(int u)
{
	if(vis[u]!=0)
	return ;
	
	vis[u]=1;
	
	cout<<u<<" ";  
	for(int x:adj[u])
	{
		dfs(x); 
	}
}
int main()
{
	int n , m; //n= no. of vertices , m=no. of edges
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++) 
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x); // creating bidirectional edge
	}
	
	int start_vertex; // vertex from which you want your DFS to start
	cin>>start_vertex;
	
	dfs(start_vertex); //  performing DFS from vertex 1
	
	
}

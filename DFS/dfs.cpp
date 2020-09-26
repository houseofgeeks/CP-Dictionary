
#include <bits/stdc++.h>

using namespace std;

//assumed size of the graph
const int N = 1e5 + 1;

vector<int> adj[N]; // for storing the edges in an adjacency list

int vis[N]={0}; // array for marking the nodes which are already visited

queue<int> q;

void bfs(int u)
{ 
	vis[u]=1;
	q.push(u);
	
	while(!q.empty())
	{
		int vertex=q.front();
		cout<<vertex<<" ";
		q.pop();
		
		for(int i:adj[vertex])
		{
			if(vis[i]==0)
			{
				vis[i]=1;
				q.push(i);
			}
		}
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
	
	bfs(start_vertex); //  performing DFS from vertex 1
	
	
}

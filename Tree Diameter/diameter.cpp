
#include <bits/stdc++.h>

using namespace std;

//assumed size of the graph
const int N = 1e5 + 1;

vector<int> adj[N]; // for storing the edges in an adjacency list

int vis[N]={0}; // array for marking the nodes which are already visited

int diameter=0; // to store the number of edges on the diameter of the tree
//for number of nodes on the diameter , do diameter++

int dfs(int u,int par)
	{
		int len=0;
		for(auto x:adj[u])
		{
			if(x!=par)
			{
				int cur=1+ dfs(x,u);
				diameter=max(diameter,cur+len);
				len=max(len,cur);
			}
		}
		return len;
	}
	
int main()
{
	int n , m; //n= no. of vertices , m=no. of edges
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++)  // m=n-1 for tree
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x); // creating bidirectional edge
	}
	diameter=0;
	dfs(1,0); //  perform DFS from vertex 1 (considering 1 as root)
	
	cout<<diameter+1<<endl;
	
	
}

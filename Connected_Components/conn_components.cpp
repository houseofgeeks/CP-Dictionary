#include<bits/stdc++.h>

using namespace std;

const int N=1E5 +5; //Assumed size of graph

vector<int> adj[N];
int vis[N]={0};

//find number of connected components in a graph using DFS

void dfs(int u)
{
	
	vis[u]=1;
	for(int x:adj[u])
	{
		if(vis[x]==0)
		dfs(x);
	}
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
	int count=0;
	for(int i=1;i<=vertices;i++)  //vertices are 1,2,......,n
	{
		if(vis[i]==0)
		{
			dfs(i);
			count++;
		}
	}
	cout<<"The number of Connected Components are : "<<count<<endl;
		
	return 0;
	
}

#include<bits/stdc++.h>

using namespace std;

const int N=1E5 +5; //Assumed size of graph

vector<int> adj[N];
int vis[N]={0};

int disc[N]={0}; // to store the discovery time of each vertex
int par[N]={0}; // to store parent of each node
int low[N]={0}; //low[v] indicates earliest visited vertex reachable from subtree rooted with v.
vector<pair<int,int >> vec; // to store bridge vertices
void BridgeDfs(int u)
{
	static int time=0;
	vis[u]=1;
	disc[u]=low[u]=++time;
	
	for(auto v:adj[u])
	{
		if(vis[v]==0)
		{
			par[v]=u;
			BridgeDfs(v);
			low[u]=min(low[u],low[v]);
			/* If the lowest vertex reachable from subtree  
             under v is  below u in DFS tree, then u-v  is a bridge*/
			if(low[v]>disc[u])
			{
					 vec.push_back({u,v});
			}
		}
		else if(v!=par[u])
		{
			low[u]=min(low[u],disc[v]);
		}
	}
	//return ;
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
	for(int i=0;i<vertices;i++)
	par[i]=-1 , vis[i]=0;
	
	for(int i=0;i<vertices;i++)   // vertex starts from 0
	{
		if(vis[i]==0)
		BridgeDfs(i);
	}
	
	if((int)vec.size()==0)
	cout<<"There are no bridges in the graph"<<endl;
	else
	{
		cout<<"The bridge Vertices are : "<<endl;
		for(int i=0;i<(int)vec.size();i++)
		cout<<vec[i].first<<" "<<vec[i].second<<endl;
	}
	
	return 0;
	
}

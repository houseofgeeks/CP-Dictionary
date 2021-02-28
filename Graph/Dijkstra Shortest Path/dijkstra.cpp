
#include<bits/stdc++.h>
using namespace std;
// Total number of vertices in graph
const V = 9;  

// For printing the shortest path
int shortest_path(int dist[], int n)
{
   cout<<"Vertex "<<"\t"<<"Distance from Source\n";
   for (int i = 0; i < V; i++)
   cout<<" \t\t \n"<< i<<" \t\t "<<dist[i];
}

// For calculating minimum distance
int minDist(int dist[], bool Set[])
{
   int min = INT_MAX, min_index;
   for (int i = 0; i < V; i++)
   if (Set[i] == false && dist[i] <= min)
   min = dist[i], min_index = i;
   return min_index;
}

// Calculate shortest paths from source to all other vertices
void Dijkstra(int g[V][V], int src)
{
   int dist[V];
   bool Set[V];
   for (int i = 0; i < V; i++)
   dist[i] = INT_MAX, Set[i] = false;
   dist[src] = 0;
   for (int c = 0; c < V- 1; c++)
   {
      int u = minDist(dist, Set);
      Set[u] = true;
      for (int j = 0; j < V; j++)
    if (!Set[j] && g[u][j] && dist[u] != INT_MAX && dist[u]+ g[u][j] < dist[j])
    {
    dist[j] = dist[u] + g[u][j];
      }
   }
   shortest_path(dist, V);
}


//DIJKSTRA
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
   
//       int G[V][V] = { 
//       { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
//       { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
//       { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
//       { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
//       { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
//       { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
//       { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
//       { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
//       { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};
      int G[V][V];
      cout<<"Enter the graph"<<endl;
      for(int i=0;i<V;i++)
       {
           for(int j=0;j<V;j++)
           {
            cin>>G[i][j];
           }
         cout<<"\n";
       }
   
   
      cout<< "\nSource vetiex is 0\n"<<endl;
      cout<<"following shows SHORTEST Distance of vertices from source vertex \n\n"<<endl;
      Dijkstra(G, 0);  
      return 0;
}

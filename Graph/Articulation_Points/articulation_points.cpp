#include<bits/stdc++.h>
using namespace std;
int t=0; //time
void dfsAP(int s,vector<vector<int>>&adj,bool*visited,bool*isAP,int*parent,int*low,int*disctime){
    int children = 0; 
    visited[s] = true; 
    disctime[s] = low[s] = ++t; // mark discovery time and low value  
    for (int u: adj[s])  //visiting all adjacents of s
    {
        if (!visited[u]) 
        { 
            children++; //mark this as a child in the recursion tree
            parent[u] = s; 
            dfsAP(u,adj, visited,isAP, parent,low, disctime); 
            // Check if the subtree rooted with u has a connection to one of the ancestors of s 
            low[s]  = min(low[s], low[u]); 
            // s is an articulation point in following cases 
            // (1) s is root of DFS tree and has two or more chilren. 
            if (parent[s] == -1 && children > 1) 
               isAP[s] = true; 
            // (2) If s is not root and low value of one of its child is more than discovery value of u. 
            if (parent[s] != -1 && low[u] >= disctime[s]) 
               isAP[s] = true; 
        } 
        else if (u != parent[s]) 
            low[s]  = min(low[s], disctime[u]); 
    } 
}
void printArticulationPoint(int V,vector<vector<int>>&adj){
    bool* visited= new bool[V];
    bool* isAP= new bool[V]; //is articulation point
    int* parent= new int[V];
    int* low=new int[V]; //low value
    int* disctime= new int[V]; //discovery time
    for(int i=0;i<V;i++){
        visited[i]=false;
        isAP[i]=false;
        parent[i]=-1;
        low[i]=INT_MAX;
        disctime[i]=INT_MAX;
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfsAP(i,adj,visited,isAP,parent,low,disctime);
        }
    }
    for(int i=0;i<V;i++){
        if(isAP[i]){
            cout<<i<<" ";
        }
    }
}
int main(){
    int V,E;
    cin>>V>>E; //V is the no of vertices and E is the no of edges, here we considers the vertices are 0,1,...,V-1
    vector<vector<int>>adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printArticulationPoint(V,adj);
}
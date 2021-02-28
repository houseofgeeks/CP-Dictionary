#include <bits/stdc++.h>
using namespace std;

// Initializes the UP table of size nlgn
// parameteres: curNode, numNodes: #nodes, maxJumpSize, up: nlogn table for parent lookup
//adj: adjacency list of the tree
// up[i][j] i represent node and j represents the 2^j and up[i][j] represents 2^jth parent of i
void init(
        int curNode, 
        int parent,
        int curDepth,
        int maxJumpSize, 
        vector<vector<int>> &up, 
        vector<int> adj[], 
        vector<int> &depth
    ) {
    up[curNode][0] = parent; // 2^0th ansestor of curNode is parent
    for(int i = 1; i <= maxJumpSize; ++i){
        if(up[curNode][i -1] != -1){
            up[curNode][i] = up[up[curNode][i -1]][i -1];
        } else {
            up[curNode][i] = -1;
        }
    }
    depth[curNode] = curDepth;
    for(auto child: adj[curNode]){
        if(child != parent){
            init(child, curNode, curDepth +1, maxJumpSize, up, adj, depth);
        }
    }
}

// This function lift node to the dist node i.e to the ansestor that is dist nodes away
// dist: the jump!
int lift(int node, int maxJumpSize, int dist, vector<vector<int>> &up){
    if(dist == 0)
        return node;
    
    for(int i = maxJumpSize; i >= 0; --i){
        if((1 << i) <= dist){
            node = up[node][i];
            dist -= (1 << i);
            if(node == -1)
                return node;
        }
    }
    return node;
}

// Finds the LCA of u and v using up and lift in lgn
int LCA(int u, int v, int maxJumpSize, vector<vector<int>> &up, vector<int> &depth){
    if(depth[u] > depth[v]){
        swap(u, v);
    }
    // u and v should at same level
    v = lift(v, maxJumpSize, (depth[v] - depth[u]), up);

    // If they are same nodes, it is itself the LCA
    if(u == v)
        return u;

    for(int i = maxJumpSize; i >= 0; --i){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}	
	}
	return up[u][0];
}

int main(){
    int numNodes;
	cin >> numNodes;

    // Adjacency list
    vector<int> adj[numNodes +1];

	for(int i = 2; i <= n; ++i){
        int x, y;
		cin >> x >> y; // input edge
		adj[y].push_back(x);
		adj[x].push_back(y);
	}

    int maxJumpSize = log2(n) +2;
    vector<vector<int>> up(n +1, vector<int>(maxJumpSize, -1));
    vector<int> depth(n +1);

    //initializing the up table
	init(1, -1, 0, maxJumpSize, up, adj, depth);
	
    cin >> x >> y; //LCA of x and  y
    cout << LCA(x, y, maxJumpSize, up, depth) << endl;
}
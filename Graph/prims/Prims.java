// A Java program for Prim's Minimum Spanning Tree (MST) algorithm.

import java.util.*;

public class Prims {

	// A utility method to find the vertex with minimum key
	// value, from the set of vertices not yet included in MST
	public static int minKey(int key[], Boolean mstSet[])
	{
		// Initialize min value
		int min = Integer.MAX_VALUE, min_index = -1;

		for (int v = 0; v < key.length; v++)
			if (mstSet[v] == false && key[v] < min) {
				min = key[v];
				min_index = v;
			}

		return min_index;
	}

	// A utility method to print the constructed MST stored in
	// parent[] as well as the total weight of the MST.
	public static void printMST(int parent[], int graph[][], int n)
	{
		long wtOfTree = 0l;

		System.out.println("Edge \tWeight");
		for (int i = 1; i < n; i++) {
			System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
			wtOfTree += graph[i][parent[i]];
		}

		System.out.println("\nWeight of tree: " + wtOfTree);
	}

	// Method to construct and print MST for a graph represented
	// using adjacency matrix representation.
	public static void primMST(int graph[][], int n)
	{
		// Array to store constructed MST.
		int parent[] = new int[n];

		// Key values used to pick minimum weight edge in cut.
		int key[] = new int[n];

		// To represent set of vertices included in MST.
		Boolean mstSet[] = new Boolean[n];

		// Initialize all keys as INFINITE.
		for (int i = 0; i < n; i++) {
			key[i] = Integer.MAX_VALUE;
			mstSet[i] = false;
		}

		// Always include first 1st vertex in MST.
		// Make key 0 so that this vertex is
		// picked as first vertex.
		key[0] = 0; 

		parent[0] = -1; // First node is always root of MST.

		// The MST will have n vertices.
		for (int count = 0; count < n - 1; count++) {
			
			// Pick thd minimum key vertex from the set of vertices
			// not yet included in MST.
			int u = minKey(key, mstSet);

			// Add the picked vertex to the MST Set.
			mstSet[u] = true;

			// Update key value and parent index of the adjacent
			// vertices of the picked vertex. Consider only those
			// vertices which are not yet included in MST.
			for (int v = 0; v < n; v++)

				// mstSet[v] is false for vertices not yet included in MST.
				// Update the key only if graph[u][v] is smaller than key[v].
				if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) {
					parent[v] = u;
					key[v] = graph[u][v];
				}
		}

		// Print the constructed MST.
		printMST(parent, graph, n);
	}

	public static void main(String[] args)
	{
		
		int graph[][] = new int[][] { 	{ 0, 2, 0, 6, 0 },
										{ 2, 0, 3, 8, 5 },
										{ 0, 3, 0, 0, 7 },
										{ 6, 8, 0, 0, 9 },
										{ 0, 5, 7, 9, 0 } };
		// Number of nodes.
		int n = 5;

		// Print the solution
		primMST(graph, n);
	}
}

/*
We created the graph given below.

     2       3
(0)-----(1)-----(2)
 |     /   \     |
 |    /     \    |
 |6  /8     5\  7|
 |  /         \  |
 | /           \ |
(3)-------------(4)
         9

Edges  Weight

0 - 1    2
0 - 3    6
1 - 2    3
1 - 3    8
1 - 4    5
2 - 4    7
3 - 4    9

 
Result (MST): 

     2       3
(0)-----(1)-----(2)
 |         \      
 |          \     
 |6         5\    
 |            \   
 |             \  
(3)             (4)

*/


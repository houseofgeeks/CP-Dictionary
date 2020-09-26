/* Program to find the minimum spanning tree and print its total weight using Kruskal's method */

#include<bits/stdc++.h>
using namespace std;

/* Function to find the representative node of the given node. */
int find(int x, vector<int> &link)
{
    while (x != link[x]) x = link[x];
    return x;
}

/* Function to check whether both nodes have same representative node or not. */
bool same(int a, int b, vector<int> &link)
{
    return find(a, link) == find(b, link);
}

/* Function to join both components and making same representative for both. */
void join(int a, int b, vector<int> &size, vector<int> &link)
{
    a = find(a, link);
    b = find(b, link);
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

/* Driver Function. */
int main()
{
    /* n and e are denoting no. of nodes and edges repectively. */
    int n, e;
    cin >> n >> e;

    /* Vector storing the Edge list as weight of the edge, starting node and ending node. */
    vector<tuple<int, int, int>> E;

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        E.push_back(make_tuple(w, a, b));
    }

    /* Sorting the edge list as per the weight of the path. */
    sort(E.begin(), E.end());


    /* Printing the Edge list representation of the graph. */
    // for (int i = 0; i < e; i++)
    // {
    //     cout << get<0>(E[i]) << " " << get<1>(E[i]) << " " << get<2>(E[i]) << endl;
    // }

    int sum = 0;

    /*Link vector stores a representative node of a particular connected component
      and size vector stores the size of that connected component */
    vector<int> link(n, 0), size(n, 1);

    /* Initially every node is single and size of it is 1. */
    for (int i = 0; i < n; i++) link[i] = i;

    /* Processing each edge as per their weight and connecting it if no cycles are formed. */
    for (int i = 0; i < e; i++)
    {
        /* Checking if the representative node is not same then we connect the edge. */
        if (!same(get<1>(E[i]), get<2>(E[i]), link))
        {
            /* Joining the nodes with the processing edge. */
            join(get<1>(E[i]), get<2>(E[i]), size, link);
            sum += get<0>(E[i]);
        }
    }

    /* Finally printing the total weight of the minimum spanning tree. */
    cout << sum << endl;

    return 0;
}


/* We can see Multi Source Dijkstra as adding a dummy node to
every source node having weight '0' and then apply
normal single source dijkstra algorithm from that dummy source.
*/

#include<bits/stdc++.h>
using namespace std;



vector<int> MultiSource_dijkstra(vector<vector<int> > &adj, map<pair<int, int>, int> &mp, int v, int src) {

    set<pair<int, int> > st;
    vector<int> dis(v + 1, INT_MAX);// vector to store the distance

    dis[src] = 0;// distance of dummy source as 0
    st.insert(make_pair(0, src));
    while (!st.empty()) {
        pair<int, int> p = *st.begin();
        st.erase(st.begin());
        int node = p.second;
        int wt = p.first;
        for (int i = 0; i < adj[node].size(); i++) {

            int k = adj[node][i];
            if (dis[k] > dis[node] + mp[make_pair(node, k)]) {

                if (dis[k] != INT_MAX) {
                    st.erase(st.find(make_pair(dis[k], k)));
                }

                dis[k] = dis[node] + mp[make_pair(node, k)];
                st.insert(make_pair(dis[k], k));
            }
        }
    }
    return dis;
}

int main() {
 
    int v, e, src;
    cout << "Enter number of vertices,number of edges and source vertex: " << endl;
    cin >> v >> e;
    vector<vector<int> > adj(v + 1); // 1 Based indexing.

    // map to store the weight of each egde
    map<pair<int, int>, int> mp;

    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w; // input format is (from_node ,to_node, weight of edge)
        adj[x].push_back(y);
        adj[y].push_back(x);
        pair<int, int> p1 = make_pair(x, y);
        pair<int, int> p2 = make_pair(y, x);
        mp[p1] = w;
        mp[p2] = w;
    }

    int no_of_sources;// store count of number of source vertices
    cin >> no_of_sources;
    vector<int> sources; // vector to store the sources
    for (int i = 0; i < no_of_sources; i++)
    {
        int x;
        cin >> x;
        sources.push_back(x);
    }

    // Creating a dummy node '0' attached to every source vertex with weight 0
    src = 0;
    for (int i = 0; i < sources.size(); i++)
    {
        int a = sources[i];
        adj[0].push_back(a);
        adj[a].push_back(0);
        mp[ {a, 0}] = 0;
        mp[ {0, a}] = 0;
    }

    std::vector<int> dis;
    dis = MultiSource_dijkstra(adj, mp, v, 0);

    // The shortest Distance for each node from any of the source vertex is stored in dis array
    for (int i = 1; i <= v; i++)
        cout << dis[i] << " ";
}

#include <bits/stdc++.h>

using namespace std;

//assumed size of the tree
const int N = 1e5 + 1;
vector<int> tree[N];
//array for marking the visited nodes
int vis[N] = {0};
//stack for storing which nodes were visited for selected clearing
stack <int> v;
int dead[N] = {0};
int centroid_tree[N];
int subtree_size[N];

//clearing nodes selectively
void clear_visited() {
	while (!v.empty()) {
		vis[v.top()] = 0;
		v.pop();
	}
	return;
}

int calculate_subtree_sizes(int src) {
	vis[src]++;
	v.push(src);
	int sum = 1;

	for (int child : tree[src]) {
		if (dead[child] == 0 && vis[child] == 0) {
			sum += calculate_subtree_sizes(child);
		}
	}

	subtree_size[src] = sum;
	return sum;
}

//decompose(source node, size of the current subtree of previous centroid, previous centroid)
void decompose(int src, int n, int previous_centroid) {

	if (dead[src] != 0) {
		return;
	}

	vis[src]++;
	v.push(src);
	centroid_tree[src] = previous_centroid;

	for (int child : tree[src]) {
		if (vis[child] == 0 && dead[child] == 0) {
			if (subtree_size[child] > n / 2) {
				decompose(child, n, previous_centroid);
				return;
			}
		}
	}

	dead[src] = 1;
	clear_visited();

	for (int child : tree[src]) {
		calculate_subtree_sizes(child);
		clear_visited();
		decompose(child , subtree_size[child], src);
	}

	return;
}

int main() {

	int n; cin >> n;

	int u, v;

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	calculate_subtree_sizes(1);
	clear_visited();
	decompose(1, n, -1);


	//printing the centroid tree in edge list form
	for (int i = 1; i <= n ; i++) {
		cout << i << ' ' << centroid_tree[i] << '\n';
	}


	return 0;
}
// Dijkstra (Single source shortest path) – TC – O(E*logV), SC – O(V)
// returns array of shortest path from source
vector<int> dijkstra(vector<vector<pair<int, int>>> adj, int s) {
	int n = adj.size();
	vector<int> d(n, INT_MAX);
	vector<int> p(n, -1);
	vector<bool> u(n, false);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!u[j] && (v == -1 || d[j] < d[v]))
			v = j;
		}
		if (d[v] == INT_MAX) break;
		u[v] = true;
		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
	return d;
}
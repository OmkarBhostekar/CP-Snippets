class BinaryLiftingLCA{
public:
	int n, l;
	vector<vector<int>> adj;

	int timer;
	vector<int> tin, tout;
	vector<vector<int>> up;

	BinaryLiftingLCA(vector<vector<int>> &g, int root){
		adj = g;
		n = g.size();
		l = ceil(log2(n));
		preprocess(root);
	}

	void dfs(int v, int p){
	    tin[v] = ++timer;
	    up[v][0] = p;
	    for (int i = 1; i <= l; ++i)
	        up[v][i] = up[up[v][i-1]][i-1];

	    for (int u : adj[v]) {
	        if (u != p)
	            dfs(u, v);
	    }

	    tout[v] = ++timer;
	}

	bool is_ancestor(int u, int v){
	    return tin[u] <= tin[v] && tout[u] >= tout[v];
	}

	// O(Log N) - for each query
	int lca(int u, int v){
	    if (is_ancestor(u, v))
	        return u;
	    if (is_ancestor(v, u))
	        return v;
	    for (int i = l; i >= 0; --i) {
	        if (!is_ancestor(up[u][i], v))
	            u = up[u][i];
	    }
	    return up[u][0];
	}

	// O(N log N) - for preprocess
	void preprocess(int root) {
	    tin.resize(n);
	    tout.resize(n);
	    timer = 0;
	    l = ceil(log2(n));
	    up.assign(n, vector<int>(l + 1));
	    dfs(root, root);
	}
};
// HOW TO USE 
// BinaryLiftingLCA solver(g,0); (g -> adj list of tree, 0 -> root of the tree)
// auto lca = solver.lca(L,R);
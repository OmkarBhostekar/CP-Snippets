typedef long long int ll;
// used for min range query on static data - (min, max, gcd)
class SparseTable {
	int n;
	int P;
	vector<ll> log; // fast log2 lookup
	vector<vector<ll>> dp; // sparse table values
	vector<vector<ll>> it; // index table
public:
	// O(n Log n) - to build the table
	SparseTable(vector<ll> &v){
		n = v.size();
		P = log2(n);
		dp.resize(P+1,vector<ll>(n+1,0));
		it.resize(P+1,vector<ll>(n+1,0));
		log.resize(n+1);

		for(int i=0;i<n;i++){
			dp[0][i] = v[i];
			it[0][i] = i;
		}

		for(int i=2;i<=n;i++)
			log[i] = log[i/2]+1;

		// build sparse table
		for(int p=1;p<=P;p++){
			for(int i=0;i+(1<<p) <= n;i++){
				ll l = dp[p-1][i];
				ll r = dp[p-1][i+(1<<(p-1))];
				dp[p][i] = min(l,r); // change according to req

				if(l<=r){
					it[p][i] = it[p-1][i];
				}else{
					it[p][i] = it[p-1][i+(1<<(p-1))];
				}
			}
		}
	}
	// O(1) - used for non overlapping - min, max, gcd
	ll query(int l, int r){
		int len = r-l+1;
		int p = log[len];
		int k = 1<<p;
		return min(dp[p][l],dp[p][r-k+1]);
	}
	// O(1) - used to get index of min/max for the range
	ll queryIndex(int l, int r){
		int len = r-l+1;
		int p = log[len];
		int left = dp[p][l];
		int right = dp[p][r - (1 << p) + 1];
		if(left <= right){
			return it[p][l];
		}
		return it[p][r-(1<<p)+1];
	}
};

class TreeNode {
public:
	int n;
	int idx;
	TreeNode* parent;
	vector<TreeNode*> child;

	TreeNode(int index) {
		this->idx = index;
		this->parent = NULL;
	}

	TreeNode(int index, TreeNode* parent){
		this->idx = index;
		this->parent = parent;
	}

	void addChildren(TreeNode* node){
		child.push_back(node);
	}
};

TreeNode* buildTree(vector<vector<int>> &g, TreeNode* root){
	int subTreeNodeCount = 1;
	for(auto v: g[root->idx]){
		if(root->parent != NULL && root->parent->idx == v) continue;
		TreeNode* ch = new TreeNode(v,root);
		root->addChildren(ch);
		buildTree(g,ch);
		subTreeNodeCount += ch->child.size();
	}
	root->n = subTreeNodeCount;
	return root;
}

TreeNode* rootTree(vector<vector<int>> &g, int rootId){
	TreeNode* root = new TreeNode(rootId);
	TreeNode* rootedTree = buildTree(g,root);
	return rootedTree;
}

class LcaEulorTour {
public:
	TreeNode* root;
	int n;
	int tourIndex = 0;
	vector<ll> nodeDepth;
	vector<TreeNode*> nodeOrder;
	vector<ll> last;
	SparseTable* minSparseTable;

	void visit(TreeNode* node, ll depth){
		nodeOrder[tourIndex] = node;
		nodeDepth[tourIndex] = depth;
		last[node->idx] = tourIndex;
		tourIndex++;
	}

	void dfs(TreeNode* node, ll depth){
		if(node == NULL) return;
		visit(node,depth);
		for(TreeNode* ch: node->child){
			dfs(ch,depth+1);
			visit(node,depth);
		}
	}

	void setup(TreeNode* root){
		int eulerTourSize = 2 * n -1  ;
		nodeOrder.resize(eulerTourSize);
		nodeDepth.resize(eulerTourSize);
		last.resize(n);
		dfs(root, 0);
		minSparseTable = new SparseTable(nodeDepth);
	}

	LcaEulorTour(vector<vector<int>> &g, int rootId){
		this->root = rootTree(g, rootId);
		this->n = g.size();
		setup(root);
	}

	TreeNode* lca(int idx1, int idx2){		
		int l = min(last[idx1],last[idx2]);
		int r = max(last[idx1],last[idx2]);
		int i = minSparseTable->queryIndex(l,r);
		return nodeOrder[i];
	}
};
// HOW TO USE 
// LcaEulorTour solver(g,0); (g -> adj list of tree, 0 -> root of the tree)
// auto treeNode = solver.lca(L,R);
// lca index = treeNode->idx;
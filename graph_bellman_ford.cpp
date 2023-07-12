// Bellman Ford (Single source shortest path with negative weights) – TC – O(V*E), SC – O(E)
struct edge{
 int a, b, cost;
}; 

void bellman_ford(vector<edge> &e, int n, int m, int s, int INF = 1000000000){
	vector<int> d (n, INF);
	d[s] = 0;
	for (;;){
		bool any = false;
		for (int j=0; j<m; ++j)
		if (d[e[j].a] < INF)
		if (d[e[j].b] > d[e[j].a] + e[j].cost){
			d[e[j].b] = d[e[j].a] + e[j].cost;
			any = true;
		}
		if (!any) break;
	}
	// display d, for example, on the screen
} 
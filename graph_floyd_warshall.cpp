// Floyd Warshall - (all pair shortest path) - TC – O(V^3), SC – O(V^2)
void printMatrix(vector<vector<int>> matrix){
	int nV = matrix.size();
	for (int i = 0; i < nV; i++) {
		for (int j = 0; j < nV; j++) {
			if (matrix[i][j] == INF)
				printf("%4s", "INF");
			else
				printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
}
void floydWarshall(vector<vector<int>> graph) {
	int n = graph.size();
	int i, j, k;
	vector<vector<int>> dist = graph;
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][j] > (dist[i][k] + dist[k][j])
				&& (dist[k][j] != INF
				&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printMatrix(dist);
}
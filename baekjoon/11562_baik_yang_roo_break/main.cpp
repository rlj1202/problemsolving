#include <iostream>
#include <cstring>

int N, M;
int adj[252][252];
int K;

int main() {
	scanf("%d %d", &N, &M);

	memset(adj, 63, sizeof(adj));
	for (int m = 1; m <= M; m++) {
		int u, v, b;
		scanf("%d %d %d", &u, &v, &b);

		adj[u][v] = 0;
		if (b == 1) adj[v][u] = 0;
		else adj[v][u] = 1;
	}

	for (int i = 1; i <= N; i++) adj[i][i] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (adj[j][k] > adj[j][i] + adj[i][k]) {
					adj[j][k] = adj[j][i] + adj[i][k];
				}
			}
		}
	}

	scanf("%d", &K);

	while (K--) {
		int s, e;
		scanf("%d %d", &s, &e);

		printf("%d\n", adj[s][e]);
	}

	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int adj[102][102];

int main() {
	memset(adj, 63, sizeof(adj));
	scanf("%d %d", &N, &M);
	for (int m = 1; m <= M; m++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adj[from][to] = min(adj[from][to], cost);
	}
	
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (i != j) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%d ", adj[i][j] == 0x3f3f3f3f ? 0 : adj[i][j]);
		printf("\n");
	}

	return 0;
}

#include <stdio.h>

#define INF 1000000009

int N, M;
int adj[1003][1003];
int a, b;

int visited[1003];
int shortest[1003];

int main() {
	scanf("%d %d", &N, &M);

	for (int from = 1; from <= N; from++) {
		for (int to = 1; to <= N; to++) {
			adj[from][to] = INF;
		}
	}
	for (int bus = 1; bus <= M; bus++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		if (adj[from][to] > cost) adj[from][to] = cost;
	}

	scanf("%d %d", &a, &b);

	//
	
	for (int i = 1; i <= N; i++) {
		shortest[i] = INF;
		visited[i] = 0;
	}
	shortest[a] = 0;

	for (int times = 1; times <= N; times++) {
		int min = INF;
		int cur;
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && shortest[i] < min) {
				min = shortest[i];
				cur = i;
			}
		}
		visited[cur] = 1;

		for (int i = 1; i <= N; i++) {
			if (adj[cur][i] != INF && visited[i] == 0) {
				if (shortest[i] > shortest[cur] + adj[cur][i]) {
					shortest[i] = shortest[cur] + adj[cur][i];
				}
			}
		}
	}

	printf("%d", shortest[b]);

	return 0;
}

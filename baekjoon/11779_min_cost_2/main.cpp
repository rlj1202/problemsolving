#include <iostream>
#include <string.h>

int N, M;
int adj[1003][1003];
int a, b;
int visited[1003];
int shortest[1003];
int parent[1003];
int path[1003];

int main() {
	scanf("%d %d", &N, &M);

	memset(adj, 63, sizeof(adj));
	for (int bus = 1; bus <= M; bus++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		if (adj[from][to] > cost) adj[from][to] = cost;
	}

	scanf("%d %d", &a, &b);

	//
	
	memset(shortest, 63, sizeof(shortest));
	shortest[a] = 0;

	for (int times = 1; times <= N; times++) {
		int min = 1 << 29;
		int cur = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && min > shortest[i]) {
				min = shortest[i];
				cur = i;
			}
		}
		visited[cur] = 1;

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && adj[cur][i] < 100000) {
				if (shortest[i] > shortest[cur] + adj[cur][i]) {
					shortest[i] = shortest[cur] + adj[cur][i];
					parent[i] = cur;
				}
			}
		}
	}

	//
	
	int cities = 1;
	int cur = b;

	while (1) {
		path[cities] = cur;
		int p = parent[cur];
		cities++;
		cur = p;
		if (p == a) break;
	}
	path[cities] = cur;

	printf("%d\n", shortest[b]);
	printf("%d\n", cities);

	for (int i = cities; i >= 1; i--) {
		printf("%d ", path[i]);
	}

	return 0;
}

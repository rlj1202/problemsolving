#include <iostream>
#include <algorithm>

#define INF 500000008

using namespace std;

int N, M;
int adj[502][502];
int shortest[502];

int main() {
	scanf("%d %d", &N, &M);

	for (int from = 1; from <= N; from++) {
		for (int to = 1; to <= N; to++)
			adj[from][to] = INF;
	}

	for (int e = 1; e <= M; e++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a][b] = min(adj[a][b], c); // c is cost, and cost can be nagative and zero.
	}

	//
	
	for (int i = 1; i <= N; i++) shortest[i] = INF;
	shortest[1] = 0;
	for (int v = 1 ; v <= N; v++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (shortest[i] != INF && shortest[j] > shortest[i] + adj[i][j]) {
					shortest[j] = shortest[i] + adj[i][j];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (shortest[j] > shortest[i] + adj[i][j]) {
				printf("-1"); // negative cycle is detected
				return 0;
			}
		}
	}
	
	//
	
	for (int i = 2; i <= N; i++) {
		int cost = shortest[i];
		printf("%d\n", cost != INF ? cost : -1);
	}

	return 0;
}

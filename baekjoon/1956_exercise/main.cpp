#include <iostream>
#include <algorithm>

#define INF 1000000009

using namespace std;

int V, E;
int adj[402][402];
int cycles[402];

int main() {
	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++)
			adj[i][j] = INF;
	}

	for (int e = 1; e <= E; e++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = c;
	}

	//
	
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				if (adj[j][k] > adj[j][i] + adj[i][k]) {
					adj[j][k] = adj[j][i] + adj[i][k];
				}
			}
		}
	}

	//
	
	for (int i = 1; i <= V; i++) {
		cycles[i] = adj[i][i];
	}

	int result = min_element(cycles + 1, cycles + 1 + V) - cycles;
	
	printf("%d", cycles[result] != INF ? cycles[result] : -1);

	return 0;
}

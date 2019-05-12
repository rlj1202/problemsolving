#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, M;
int from[6003];
int to[6003];
int cost[6003];

int minCost[502];

int main() {
	// read a number of vertices and edges
	scanf("%d %d", &N, &M);

	// read edges
	for (int m = 1; m <= M; m++)
		scanf("%d %d %d", from + m, to + m, cost + m);

	// do bellman ford
	memset(minCost, 0x3f, sizeof(minCost));
	minCost[1] = 0;

	for (int n = 1; n <= N - 1; n++)
		for (int m = 1; m <= M; m++)
			if (minCost[from[m]] != INF) minCost[to[m]] = min(minCost[to[m]], minCost[from[m]] + cost[m]);

	// detect negative cycle
	for (int m = 1; m <= M; m++) {
		if (minCost[from[m]] != INF && minCost[to[m]] > minCost[from[m]] + cost[m]) {
			printf("-1\n");
			return 0;
		}
	}

	// print results
	for (int n = 2; n <= N; n++)
		printf("%d\n", minCost[n] == INF ? -1 : minCost[n]);

	return 0;
}

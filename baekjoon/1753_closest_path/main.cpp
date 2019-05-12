#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000009

using namespace std;

int V, E;
int K;

vector<pair<int, int>> adj[20004];

priority_queue<pair<int, int>> shortest;
int visited[20004];
int cost[20004];

int main() {
	scanf("%d %d", &V, &E);

	scanf("%d", &K);
	
	for (int e = 1; e <= E; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		adj[u].push_back(make_pair(w, v));
		// there can be multiple edges with different weight
		// but that will be handled when calculating minimum cost
	}

	for (int i = 1; i <= V; i++) cost[i] = INF;
	cost[K] = 0;
	shortest.push(make_pair(-cost[K], K));

	while (shortest.size() > 0) {
		pair<int, int> cur = shortest.top(); shortest.pop();

		if (visited[cur.second]) continue;
		visited[cur.second] = 1;

		vector<pair<int, int>>::iterator iter;
		for (iter = adj[cur.second].begin(); iter != adj[cur.second].end(); iter++) {
			if (!visited[iter->second]) {
				if (cost[iter->second] > cost[cur.second] + iter->first) {
					cost[iter->second] = cost[cur.second] + iter->first;
					shortest.push(make_pair(-cost[iter->second], iter->second));
				}
			}
		}
	}
	
	//
	
	for (int i = 1; i <= V; i++) {
		int c = cost[i];
		if (c != INF) printf("%d\n", c);
		else printf("INF\n");
	}

	return 0;
}

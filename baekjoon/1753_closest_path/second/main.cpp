#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const static int INF = 0x3f3f3f3f;

int V, E;
int K;

vector<pair<int, int>> adj[20004];
priority_queue<pair<int, int>> closest;
int dist[20004];

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	for (int e = 1; e <= E; e++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a].push_back(make_pair(c, b));
	}

	memset(dist, INF, sizeof(dist));
	dist[K] = 0;
	closest.push(make_pair(-dist[K], K));

	while (!closest.empty()) {
		pair<int, int> cur = closest.top();
		closest.pop();
		if (dist[cur.second] < -cur.first) continue;

		for (pair<int, int> edge : adj[cur.second]) {
			int newDist = edge.first + dist[cur.second];

			if (dist[edge.second] > newDist) {
				dist[edge.second] = newDist;

				closest.push(make_pair(-newDist, edge.second));
			}
		}
	}

	for (int v = 1; v <= V; v++) {
		int d = dist[v];
		if (d == INF) printf("INF\n");
		else printf("%d\n", d);
	}
	
	return 0;
}

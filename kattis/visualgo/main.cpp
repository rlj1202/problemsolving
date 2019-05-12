#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int V, E;
vector<pair<int, int>> adj[10004];
int s, t;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int mindist[10004];

unsigned long long pathcount[10004];

int main() {
	scanf("%d %d", &V, &E);
	for (int e = 0; e < E; e++) {
		int u, v;
		int w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({w, v});
		//adj[v].push_back({w, u});
	}
	scanf("%d %d", &s, &t);

	memset(mindist, INF, sizeof(mindist));
	mindist[s] = 0;
	pq.push({0, s});
	
	pathcount[s] = 1;

	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		if (cur.first > mindist[cur.second]) continue;

		for (pair<int, int> edge : adj[cur.second]) {
			int newdist = cur.first + edge.first;

			if (mindist[edge.second] > newdist) {
				mindist[edge.second] = newdist;

				pq.push({newdist, edge.second});

				pathcount[edge.second] = pathcount[cur.second];
			} else if (mindist[edge.second] == newdist) {
				pathcount[edge.second] += pathcount[cur.second];
			}
		}
	}

	printf("%llu\n", pathcount[t]);

	return 0;
}

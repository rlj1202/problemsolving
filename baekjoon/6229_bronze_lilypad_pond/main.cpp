#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct Node { int m, n; };

const int dm[] = {1, -1, 1, -1};
const int dn[] = {1, 1, -1, -1};

const int INF = 0x3f3f3f3f;

int M, N, M1, M2;
int grid[32][32];

Node nodes[902];
int nodeslen;

int startnode;
int endnode;

vector<int> adj[902];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool out[902];
int minleap[902];

int main() {
	scanf("%d %d %d %d", &M, &N, &M1, &M2);
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			int value;
			scanf("%d", &value);
			if (value == 0 || value == 2) continue;

			nodeslen++;

			nodes[nodeslen] = {m, n};
			grid[m][n] = nodeslen;

			if (value == 3) startnode = nodeslen;
			else if (value == 4) endnode = nodeslen;
		}
	}

	for (int node = 1; node <= nodeslen; node++) {
		Node cur = nodes[node];
		for (int i = 0; i < 4; i++) {
			int m = cur.m + M1 * dm[i];
			int n = cur.n + M2 * dn[i];
			if (m < 0 || M <= m) continue;
			if (n < 0 || N <= n) continue;

			if (grid[m][n] == 0) continue;

			adj[grid[cur.m][cur.n]].push_back(grid[m][n]);
		}
		if (M1 != M2) for (int i = 0; i < 4; i++) {
			int m = cur.m + M2 * dm[i];
			int n = cur.n + M1 * dn[i];
			if (m < 0 || M <= m) continue;
			if (n < 0 || N <= n) continue;

			if (grid[m][n] == 0) continue;

			adj[grid[cur.m][cur.n]].push_back(grid[m][n]);
		}
	}

	memset(minleap, INF, sizeof(minleap));
	minleap[startnode] = 0;
	pq.push({0, startnode});

	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		if (out[cur.second]) continue;
		out[cur.second] = true;

		for (int next : adj[cur.second]) {
			int newleap = cur.first + 1;

			if (minleap[next] > newleap) {
				minleap[next] = newleap;

				pq.push({newleap, next});
			}
		}
	}

	printf("%d\n", minleap[endnode]);

	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Node { int m, n; bool added; };

struct Cost { int lilypad, leap; int node; };

bool operator== (const Cost &a, const Cost &b) {
	return a.lilypad == b.lilypad && a.leap == b.leap;
}

bool operator< (const Cost &a, const Cost &b) {
	if (a.lilypad == b.lilypad) return a.leap < b.leap;
	return a.lilypad < b.lilypad;
}

bool operator> (const Cost &a, const Cost &b) {
	if (a.lilypad == b.lilypad) return a.leap > b.leap;
	return a.lilypad > b.lilypad;
}

const int INF = 0x3f3f3f3f;

const int dm[] = {1, -1, -1, 1, 2, -2, -2, 2};
const int dn[] = {2, 2, -2, -2, 1, 1, -1, -1};

int M, N;
int grid[32][32];

Node nodes[902];
int nodeslen;

int startnode;
int endnode;

vector<int> adj[902];

priority_queue<Cost, vector<Cost>, greater<Cost>> pq;
Cost mincost[902];
long long pathcount[902];

int main() {
	scanf("%d %d", &M, &N);
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			int value;
			scanf("%d", &value);

			if (value == 2) grid[m][n] = -1;
			else if (value != 0) {
				nodeslen++;

				nodes[nodeslen] = {m, n, false};
				grid[m][n] = nodeslen;

				if (value == 3) startnode = nodeslen;
				else if (value == 4) endnode = nodeslen;
			}
		}
	}

	for (int nodeidx = 1; nodeidx <= nodeslen; nodeidx++) {
		Node cur = nodes[nodeidx];

		for (int i = 0; i < 8; i++) {
			int m = cur.m + dm[i];
			int n = cur.n + dn[i];
			if (m < 0 || M <= m) continue;
			if (n < 0 || N <= n) continue;

			if (grid[m][n] == -1) continue;
			
			if (grid[m][n] == 0) {
				nodeslen++;

				nodes[nodeslen] = {m, n, true};
				grid[m][n] = nodeslen;
			}

			adj[nodeidx].push_back(grid[m][n]);
		}
	}

	memset(mincost, INF, sizeof(mincost));
	pq.push(mincost[startnode] = {0, 0, startnode});

	pathcount[startnode] = 1;

	while (!pq.empty()) {
		Cost cur = pq.top(); pq.pop();
		if (mincost[cur.node] < cur) continue;

		for (int next : adj[cur.node]) {
			Cost newcost = {cur.lilypad + nodes[next].added, cur.leap + 1, next};

			if (mincost[next] > newcost) {
				pq.push(mincost[next] = newcost);

				pathcount[next] = pathcount[cur.node];
			} else if (mincost[next] == newcost) {
				pathcount[next] += pathcount[cur.node];
			}
		}
	}

	if (mincost[endnode].lilypad == INF) {
		printf("%d\n", -1);
	} else {
		printf("%d\n", mincost[endnode].lilypad);
		printf("%d\n", mincost[endnode].leap);
		printf("%lld\n", pathcount[endnode]);
	}

	return 0;
}

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const static int INF = 0x3f3f3f3f;

struct Edge {
	int from;
	int to;
	int cost;
	int index;
};

struct Compare {
	bool operator() (const Edge &a, const Edge &b) {
		return a.cost > b.cost;
	}
};

int N, M, K;
vector<Edge> adj[300005];

priority_queue<Edge, vector<Edge>, Compare> closest;
int minCost[300005];

int parents[300005];

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int m = 1; m <= M; m++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a].push_back(Edge{a, b, c, m});
		adj[b].push_back(Edge{b, a, c, m});
	}

	memset(minCost, 0x3f, sizeof(int) * (N + 2));
	minCost[1] = 0;
	closest.push(Edge{0, 1, 0, 0});

	while (!closest.empty()) {
		Edge cur = closest.top(); closest.pop();
		if (cur.cost > minCost[cur.to]) continue;
		parents[cur.to] = cur.from;

		for (Edge edge : adj[cur.to]) {
			int newCost = minCost[cur.to] + edge.cost;
			if (minCost[edge.to] > newCost) {
				minCost[edge.to] = newCost;
				closest.push(Edge{cur.to, edge.to, newCost, edge.index});
			}
		}
	}

	for (int v = 1; v <= N; v++) {
		printf("[%d] : %d, { ", v, minCost[v]);
		int cur = v;
		while (cur != 0) {
			printf("%d ", cur);
			cur = parents[cur];
		}

		printf("}\n");
	}

	return 0;
}

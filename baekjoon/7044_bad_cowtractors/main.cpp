#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge { int dest, cost; };

bool operator< (const Edge &a, const Edge &b) {
	return a.cost < b.cost;
}

int N, M;
vector<Edge> adj[1003];

bool out[1003];
priority_queue<Edge> pq;

int main() {
	scanf("%d %d", &N, &M);
	for (int m = 0; m < M; m++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	int remains = N;
	int total_cost = 0;

	out[1] = true;
	remains--;
	for (Edge e : adj[1]) {
		pq.push(e);
	}

	while (!pq.empty()) {
		Edge cur = pq.top(); pq.pop();
		if (out[cur.dest]) continue;

		total_cost += cur.cost;
		out[cur.dest] = true;
		remains--;

		for (Edge next : adj[cur.dest]) {
			pq.push(next);
		}
	}

	if (remains == 0) printf("%d\n", total_cost);
	else printf("%d\n", -1);

	return 0;
}

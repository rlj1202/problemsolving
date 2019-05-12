#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge { int dest, cost; };

bool operator> (const Edge &a, const Edge &b) {
	if (a.cost == b.cost) return a.dest > b.dest;
	else return a.cost > b.cost;
}

int N, M;
vector<Edge> adj[200005];

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
bool visited[200005];

int main() {
	scanf("%d %d", &N, &M);
	for (int m = 0; m < M; m++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	visited[1] = true;
	for (Edge e : adj[1]) pq.push(e);

	int cnt = 0;

	while (!pq.empty()) {
		Edge cur = pq.top();
		pq.pop();
		if (visited[cur.dest]) continue;

		while (!pq.empty()
				&& pq.top().cost == cur.cost) {
			Edge next = pq.top();
			pq.pop();

			cnt++;
			pq.push({next.dest, next.cost + 1});
		}

		visited[cur.dest] = true;
		for (Edge e : adj[cur.dest]) pq.push(e);
	}

	printf("%d\n", cnt);

	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Edge {
	int dest, length;

	bool operator> (const Edge &o) const {
		return length > o.length;
	}
};

int N, R;
vector<Edge> adj[5003];

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
bool out[5003];

int minlen[5003];
int secondlen[5003];

int main() {
	scanf("%d %d", &N, &R);
	for (int r = 0; r < R; r++) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}

	memset(minlen, 0x3f, sizeof(minlen));
	memset(secondlen, 0x3f, sizeof(secondlen));

	pq.push({1, 0});

	while (!pq.empty()) {
		Edge cur = pq.top(); pq.pop();
		if (out[cur.dest]) continue;
		out[cur.dest] = true;

		for (Edge edge : adj[cur.dest]) {
			int newlen = cur.length + edge.length;

			if (minlen[edge.dest] > newlen) {
				secondlen[edge.dest] = minlen[edge.dest];
				minlen[edge.dest] = newlen;

				pq.push({edge.dest, newlen});
			} else if (secondlen[edge.dest] > newlen) {
				secondlen[edge.dest] = newlen;

				pq.push({edge.dest, newlen});
			}
		}
	}

	printf("%d\n", secondlen[N]);

	return 0;
}

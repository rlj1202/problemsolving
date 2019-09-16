#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

union Planet {
	struct { int x, y, z; int id; };
	struct { int coords[3]; };
};

struct Edge {
	Planet *to;
	int cost;

	bool operator> (const Edge &o) const {
		return cost > o.cost;
	}
};

const int INF = 0x3f3f3f3f;

int N;
Planet planets[100005];

Planet *planetsort[100005];

vector<Edge> adj[100005];

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
bool out[100005];

struct PlanetSort {
	int coord;
	bool operator() (const Planet *a, const Planet *b) {
		return a->coords[coord] < b->coords[coord];
	}
};

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		planets[n] = {x, y, z, n};
		planetsort[n] = planets + n;
	}

	for (int i = 0; i < 3; i++) {
		sort(planetsort, planetsort + N, PlanetSort{i});

		Planet *prev = NULL;
		for (int n = 0; n < N; n++) {
			Planet *cur = planetsort[n];
			Planet *next = planetsort[n + 1];

			if (prev) adj[cur->id].push_back({prev, abs(prev->coords[i] - cur->coords[i])});
			if (next) adj[cur->id].push_back({next, abs(next->coords[i] - cur->coords[i])});

			prev = cur;
		}
	}

	pq.push({planets + 0, 0});

	int mincost = 0;

	while (!pq.empty()) {
		Edge cur = pq.top(); pq.pop();
		if (out[cur.to->id]) continue;
		out[cur.to->id] = true;
		mincost += cur.cost;

		for (Edge edge : adj[cur.to->id]) {
			pq.push(edge);
		}
	}
	
	printf("%d\n", mincost);

	return 0;
}

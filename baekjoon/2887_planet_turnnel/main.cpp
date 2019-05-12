#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Planet {
	int coords[3];
	int neigh[3][2];
};

struct Edge {
	int from, to;
	int cost;
};

bool operator< (const Edge &p, const Edge &q) {
	return p.cost > q.cost;
}

int N;
Planet planets[100005];

int sorted[100005];

priority_queue<Edge> smallest;
int out[100005];
int result;

struct Compare {
	int coord;
	bool operator() (const int p, const int q) {
		return planets[p].coords[coord] < planets[q].coords[coord];
	}
};

int main() {
	// init
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		planets[n] = Planet{{x, y, z}, {}};
		sorted[n] = n;
	}

	// sort and make a linked list
	for (int coord = 0; coord < 3; coord++) {
		sort(sorted + 1, sorted + N + 1, Compare{coord});

		for (int n = 1; n <= N; n++) {
			Planet &p = planets[sorted[n]];
			p.neigh[coord][0] = sorted[n - 1];
			p.neigh[coord][1] = sorted[n + 1];
		}
	}

	// use prim's algorithm
	smallest.push(Edge{1, 1, 0});

	while (!smallest.empty()) {
		Edge cur = smallest.top(); smallest.pop();
		int p = cur.to;

		if (out[p]) continue;
		out[p] = 1;
		result += cur.cost;

		for (int coord = 0; coord < 3; coord++) {
			int l = planets[p].neigh[coord][0];
			int r = planets[p].neigh[coord][1];

			if (!out[l]) {
				planets[l].neigh[coord][1] = r;
				smallest.push(Edge{p, l, abs(planets[p].coords[coord] - planets[l].coords[coord])});
			}

			if (!out[r]) {
				planets[r].neigh[coord][0] = l;
				smallest.push(Edge{p, r, abs(planets[p].coords[coord] - planets[r].coords[coord])});
			}
		}

		printf("test: %d\n", cur.cost);
	}

	// print result
	printf("%d\n", result);

	return 0;
}

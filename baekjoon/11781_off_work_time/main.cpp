#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
	int dest;
	int length;
	int traffic;
};

int N, M;
int S, E;

vector<Edge> adj[5003];

priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
bool out[5003];
double mintime[5003];

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d", &S, &E);
	for (int m = 0; m < M; m++) {
		int a, b;
		int l;
		int t1, t2;
		scanf("%d %d %d %d %d", &a, &b, &l, &t1, &t2);

		adj[a].push_back({b, l, t1});
		adj[b].push_back({a, l, t2});
	}

	fill(mintime + 1, mintime + 1 + N, 1e10);

	mintime[1] = 0;
	pq.push({0, 1});

	while (!pq.empty()) {
		pair<double, int> cur = pq.top(); pq.pop();
		if (out[cur.second]) continue;
		out[cur.second] = true;

		for (Edge next : adj[cur.second]) {
			double newtime = cur.first + next.length;

			if (next.traffic && S <= cur.first + next.length) {
				double start = max(cur.first, (double) S);
				double delayed = (E - start) / 2.0;
				double end = min(start + delayed, cur.first + next.length);
				if (delayed > 0) newtime += end - start;
			}

			if (mintime[next.dest] > newtime) {
				mintime[next.dest] = newtime;
				pq.push({newtime, next.dest});
			}
		}
	}

	double maxtime = 0;
	for (int n = 1; n <= N; n++) maxtime = max(maxtime, mintime[n]);

	printf("%lf\n", maxtime);

	return 0;
}

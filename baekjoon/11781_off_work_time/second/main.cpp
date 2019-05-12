#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Edge {
	int dest;
	double len;
	int traffic;
};

int N, M;
double S, E;

vector<Edge> adj[5003];

priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
int front, rear;
bool out[5003];
double mintime[5003];

int main() {
	scanf("%d %d %lf %lf", &N, &M, &S, &E);
	for (int m = 0; m < M; m++) {
		int a, b;
		double l;
		int t1, t2;
		scanf("%d %d %lf %d %d", &a, &b, &l, &t1, &t2);
		adj[a].push_back({b, l, t1});
		adj[b].push_back({a, l, t2});
	}

	fill(mintime + 1, mintime + N + 1, 2e10);

	mintime[1] = 0.0;
	pq.push({0.0, 1});

	while (!pq.empty()) {
		pair<double, int> cur = pq.top(); pq.pop();
		if (out[cur.second]) continue;
		out[cur.second] = true;

		for (Edge next : adj[cur.second]) {
			double start = 0; // where traffic jam starts
			double end = 0; // where traffic jam ends

			if (next.traffic == 1) {
				if (cur.first < S)
					start = min(S - cur.first, next.len);

				end = min(next.len, start + ((E - cur.first) - start) / 2.0);
			}

			double time = cur.first;
			time += start;
			time += (end - start) * 2.0;
			time += next.len - end;

			if (mintime[next.dest] > time) {
				mintime[next.dest] = time;

				pq.push({time, next.dest});
			}
		}
	}

	double maxtime = 0;
	for (int n = 1; n <= N; n++) {
		maxtime = max(maxtime, mintime[n]);
	}

	if ((long long) (maxtime * 2.0) % 2 == 1) printf("%.1lf\n", maxtime);
	else printf("%lld\n", (long long) maxtime);

	return 0;
}

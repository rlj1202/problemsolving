#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge {
	int dest;
	long long len;
	int traffic;
};

int N, M;
long long S, E;

vector<Edge> adj[5003];

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
bool out[5003];
long long mintime[5003];

int main() {
	scanf("%d %d %lld %lld", &N, &M, &S, &E);
	for (int m = 0; m < M; m++) {
		int a, b;
		long long l;
		int t1, t2;
		scanf("%d %d %lld %d %d", &a, &b, &l, &t1, &t2);
		l *= 2;
		adj[a].push_back({b, l, t1});
		adj[b].push_back({a, l, t2});
	}

	S *= 2;
	E *= 2;

	memset(mintime, 0x7f, sizeof(mintime));

	mintime[1] = 0;
	pq.push({0, 1});

	while (!pq.empty()) {
		pair<long long, int> cur = pq.top(); pq.pop();
		if (out[cur.second]) continue;
		out[cur.second] = true;

		for (Edge next : adj[cur.second]) {
			long long start = 0; // where traffic jam starts
			long long end = 0; // where traffic jam ends

			if (next.traffic == 1) {
				if (cur.first < S) {
					start = S - cur.first;
				} else {
					start = 0;
				}

				if (E < cur.first) {
					end = 0;
				} else {
					end = start + ((E - cur.first) - start) / 2;
				}

				start = max(start, 0LL);
				start = min(start, next.len);

				end = max(end, 0LL);
				end = min(end, next.len);
			}

			long long time = cur.first;
			time += start;
			time += (end - start) * 2;
			time += (next.len - end);

			/*
			printf("\t%2d -> %2d ,\t %2llds %2llds %2llds ,\t %2lldm %2lldm ,\t %lld %lld\n",
					cur.second, next.dest,
					start, (end - start) * 2, next.len - end,
					start, end,
					(S - cur.first), S);
					*/

			if (mintime[next.dest] > time) {
				mintime[next.dest] = time;

				pq.push({time, next.dest});
			}
		}
	}

	long long maxtime = 0;
	for (int n = 1; n <= N; n++) {
		maxtime = max(maxtime, mintime[n]);
	}

	printf("%lld", maxtime / 2);
	if (maxtime % 2 == 1) printf(".5");
	printf("\n");

	return 0;
}

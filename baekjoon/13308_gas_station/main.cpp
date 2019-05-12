#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int perLiters[3003];
vector<pair<int, int>> adj[3003];

priority_queue<pair<long long, int>> greedy;
long long minCost[3003][3003];

long long shortest[3003];

int main() {
	scanf("%d %d", &N, &M);

	for (int n = 1; n <= N; n++) {
		scanf("%d", perLiters + n);
	}
	for (int m = 1; m <= M; m++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}

	memset(minCost, 63, sizeof(minCost));

	for (int city = 1; city < N; city++) {
		minCost[city][city] = 0;
		greedy.push(make_pair(0, city));

		while (!greedy.empty()) {
			pair<long long, int> cur = greedy.top(); greedy.pop();
			if (-cur.first > minCost[city][cur.second]) continue;

			for (pair<int, int> edge : adj[cur.second]) {
				long long newDistance = -cur.first + edge.first * perLiters[city];

				if (minCost[city][edge.second] > newDistance) {
					minCost[city][edge.second] = newDistance;
					greedy.push(make_pair(-newDistance, edge.second));
				}
			}
		}
	}

	memset(shortest, 63, sizeof(shortest));
	shortest[1] = 0;
	greedy.push(make_pair(0, 1));

	while (!greedy.empty()) {
		pair<long long, int> cur = greedy.top(); greedy.pop();
		if (-cur.first > shortest[cur.second]) continue;

		for (int i = 1; i <= N; i++) {
			long long newDistance = -cur.first + minCost[cur.second][i];

			if (shortest[i] > newDistance) {
				shortest[i] = newDistance;
				greedy.push(make_pair(-newDistance, i));
			}
		}
	}

	printf("%lld\n", shortest[N]);

	return 0;
}

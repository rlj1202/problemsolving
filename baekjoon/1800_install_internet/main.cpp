#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge { int dest, cost; };

vector<Edge> adj[1003];
int maxcost;

bool visited[1003][1003];
queue<pair<int, int>> q;

bool check_possible(int k, int mincost, int n) {
	memset(visited, 0, sizeof(visited));

	visited[1][0] = true;
	q.push({1, 0});

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (Edge edge : adj[cur.first]) {
			if (edge.cost <= mincost) {
				if (visited[edge.dest][cur.second]) continue;

				visited[edge.dest][cur.second] = true;
				q.push({edge.dest, cur.second});
			} else {
				if (visited[edge.dest][cur.second + 1]) continue;

				if (cur.second + 1 <= k) {
					visited[edge.dest][cur.second + 1] = true;
					q.push({edge.dest, cur.second + 1});
				}
			}
		}
	}

	return visited[n][k];
}

int main() {
	int N, P, K;
	scanf("%d %d %d", &N, &P, &K);
	for (int p = 0; p < P; p++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		adj[a].push_back({b, cost});
		adj[b].push_back({a, cost});
		maxcost = max(maxcost, cost);
	}

	int l = 0, r = maxcost;
	int mid = (l + r) / 2;

	while (l < r) {
		if (check_possible(K, mid, N) == true) {
			r = mid;
		} else {
			l = mid + 1;
		}
		mid = (l + r) / 2;
	}

	if (check_possible(K, mid, N) == true) printf("%d\n", mid);
	else printf("-1\n");

	return 0;
}

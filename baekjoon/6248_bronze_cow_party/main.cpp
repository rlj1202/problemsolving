#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, M, X;
vector<pair<int, int>> adj[1003];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool out[1003];
int mindist[1003];

int main() {
	scanf("%d %d %d", &N, &M, &X);
	for (int m = 0; m < M; m++) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		adj[a].push_back({t, b});
		adj[b].push_back({t, a});
	}

	memset(mindist, INF, sizeof(mindist));
	pq.push({mindist[X]= 0, X});

	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		if (out[cur.second]) continue;
		out[cur.second] = true;

		for (pair<int, int> edge : adj[cur.second]) {
			int newdist = cur.first + edge.first;

			if (mindist[edge.second] > newdist)
				pq.push({mindist[edge.second] = newdist, edge.second});
		}
	}

	int maxtime = 0;
	for (int n = 1; n <= N; n++) maxtime = max(maxtime, mindist[n]);

	printf("%d\n", maxtime * 2);

	return 0;
}

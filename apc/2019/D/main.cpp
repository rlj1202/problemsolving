#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, E;
vector<int> adj[100005];

int indegree[100005];

long long cutedges[100005];
int cutedgeslen;

void travel(int from, int to, int len) {
	if (to == N) {
		if (len % 2 == 1) cutedges[cutedgeslen++] = (from - 1) + (to - 1) * 100000;
		return;
	}
	
	for (int next : adj[to]) {
		travel(to, next, len + 1);
	}
}

int main() {
	scanf("%d %d", &N, &E);
	for (int e = 0; e < E; e++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		indegree[v]++;
	}

	int result = INF;

	for (int v = 1; v <= N; v++) {
		if (indegree[v]) continue;

		cutedgeslen = 0;

		for (int next : adj[v]) {
			travel(v, next, 1);
		}
	
		sort(cutedges, cutedges + cutedgeslen);
		cutedgeslen = unique(cutedges, cutedges + cutedgeslen) - cutedges;

		result = min(result, cutedgeslen);
	}

	if (result != INF) printf("%d\n", result);
	else printf("%d\n", -1);

	return 0;
}

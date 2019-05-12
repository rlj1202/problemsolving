#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define INF 100000000011

using namespace std;

int N, E;
vector<pair<long long, int>> adj[802];
int P, Q;

priority_queue<pair<long long, int>> shortest;
int out[802];

long long minFromStart[802];
long long minFromP[802];
long long minFromQ[802];

void dijkstra(long long *min, int start) {
	memset(out, 0, sizeof(out));
	for (int i = 1; i <= N; i++) min[i] = INF;

	min[start] = 0;
	shortest.push(make_pair(-min[start], start));

	while (shortest.size() > 0) {
		pair<int, int> cur = shortest.top(); shortest.pop();
		if (out[cur.second]) continue;
		out[cur.second] = 1;

		vector<pair<long long , int>>::iterator iter;
		for(iter = adj[cur.second].begin(); iter != adj[cur.second].end(); iter++) {
			if (!out[iter->second]) {
				if (min[iter->second] > min[cur.second] + iter->first) {
					min[iter->second] = min[cur.second] + iter->first;
					shortest.push(make_pair(-min[iter->second], iter->second));
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &E);

	for (int e = 1; e <= E; e++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}

	scanf("%d %d", &P, &Q);

	dijkstra(minFromStart, 1);
	dijkstra(minFromP, P);
	dijkstra(minFromQ, Q);
	
	long long min[10];
	min[0] = minFromStart[P] + minFromP[Q] + minFromQ[N];
	min[1] = minFromStart[Q] + minFromQ[P] + minFromP[N];
	min[2] = minFromStart[P] + minFromP[Q] + minFromQ[P] + minFromP[N];
	min[3] = minFromStart[Q] + minFromQ[P] + minFromP[Q] + minFromQ[N];
	min[4] = minFromStart[P] + minFromP[1] + minFromStart[Q] + minFromQ[N];
	min[5] = minFromStart[Q] + minFromQ[1] + minFromStart[P] + minFromP[N];
	min[6] = minFromStart[P] + minFromP[N] + minFromQ[N]*2;
	min[7] = minFromStart[Q] + minFromQ[N] + minFromP[N]*2;
	min[8] = minFromStart[N] + minFromP[N] + minFromP[Q] + minFromQ[N];
	min[9] = minFromStart[N] + minFromP[N]*2 + minFromQ[N]*2;

	int result = min_element(min, min + 10) - min;

	printf("%lld\n", min[result] >= INF ? -1 : min[result]);

	return 0;
}

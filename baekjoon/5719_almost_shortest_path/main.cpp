#include <iostream>
#include <cstring>
#include <queue>

#define INF 1000000009

using namespace std;

int N, M;
int S, D; // zero-indexed
vector<pair<int, int>> adj[502];

struct Node {
	int distance;
	vector<int> parents;
	Node() : distance(0) {}
	Node(int d) : distance(d) {}
	Node(int d, int parent) : distance(d) {
		parents.push_back(parent);
	}
};

priority_queue<pair<int, int>> shortest;
int out[502];
Node minPath[502];

void dijkstra() {
	memset(out, 0, sizeof(out));
	for (int i = 0; i < N; i++) minPath[i] = Node(INF);

	minPath[S] = Node(0);
	shortest.push(make_pair(-minPath[S].distance, S));

	while (shortest.size() > 0) {
		pair<int, int> cur = shortest.top(); shortest.pop();
		if (out[cur.second]) continue;
		out[cur.second] = 1;

		vector<pair<int, int>>::iterator iter;
		for (iter = adj[cur.second].begin(); iter != adj[cur.second].end(); iter++) {
			if (!out[iter->second]) {
				int newDistance = minPath[cur.second].distance + iter->first;

				if (minPath[iter->second].distance > newDistance) {
					minPath[iter->second] = Node(newDistance, cur.second);
					shortest.push(make_pair(-minPath[iter->second].distance, iter->second));
				} else if (minPath[iter->second].distance == newDistance) {
					minPath[iter->second].parents.push_back(cur.second);
					shortest.push(make_pair(-minPath[iter->second].distance, iter->second));
				}
			}
		}
	}
}

void removeEdges(int cur) {
	if (cur == S) return;

	vector<int>::iterator iter;
	for (iter = minPath[cur].parents.begin(); iter != minPath[cur].parents.end(); iter++) {
		vector<pair<int, int>>::iterator edges;
		for (edges = adj[*iter].begin(); edges != adj[*iter].end(); edges++) {
			if (edges->second == cur) edges->first = INF;
		}
		removeEdges(*iter);
	}
}

int main() {
	while (true) {
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) break;
		scanf("%d %d", &S, &D);

		for (int m = 0; m < M; m++) {
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);

			adj[u].push_back(make_pair(p, v));
		}

		dijkstra();
		removeEdges(D);
		dijkstra();

		int result = minPath[D].distance;
		printf("%d\n", result != INF ? result : -1);

		for (int i = 0; i < N; i++) adj[i].clear();
	}

	return 0;
}

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point { int x, y; };

struct Edge {
	int x, y;
	int vertexid;

	bool operator< (const Edge &o) const {
		int v = x*o.y - y*o.x;
		return v > 0;
	}
};

Point points[100005];
vector<int> adj[100005];

vector<int> left[100005];
vector<bool> angleused[100005];
int angles[100005];

Edge edges[100005];

int main() {
	// read input
	int N, M;
	scanf("%d %d", &N, &M);

	for (int n = 1; n <= N; n++) {
		int x, y;
		scanf("%d %d", &x, &y);
		points[n] = {x, y};
	}

	for (int m = 0; m < M; m++) {
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	//
	for (int n = 1; n <= N; n++) {
		Point cur = points[n];

		sort(adj[n].begin(), adj[n].end());
		left[n].resize(adj[n].size());
		angles[n] = adj[n].size();
		
		for (int i = 0; i < adj[n].size(); i++) {
			int next = adj[n][i];

			Point p = points[next];
			edges[i] = {p.x - cur.x, p.y - cur.y, next};
		}

		sort(edges, edges + adj[n].size());

		int prev = edges[adj[n].size() - 1].vertexid;
		for (int i = 0; i < adj[n].size(); i++) {
			int index =
				lower_bound(adj[n].begin(), adj[n].end(), edges[i].vertexid)
				- adj[n].begin();

			left[n][index] = prev;
			prev = edges[i].vertexid;
		}
	}

	//
	bool update = true;
	while (update) {
		update = false;

		for (int n = 1; n <= N; n++) {
			if (angles[n] == 0) continue;
			update = true;

			int prev;
			int cur = n;
			int next;
			for (int i = 0; i < adj[n].size(); i++) {
				if (!angleused[n][i]) {
					prev = adj[n][i];
					next = left[n][i];
				}
			}

			while (next != n) {
				
				next = left[next][];
			}
		}
	}

	// print result
	printf("%d\n", 0);

	return 0;
}

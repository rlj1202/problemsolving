#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int dest;
	int capacity;
	int flow;
	int residual_idx;
};

const int INF = 0x3f3f3f3f;

vector<Edge> adj[20004];

// for bfs
int queue[20004];
bool visited[20004];
int front, rear;

// for back-tracking
int backvert[20004];
int backidx[20004];

void add_edge(int u, int v, int c) {
	adj[u].push_back({v, c, 0, (int) adj[v].size()});
	adj[v].push_back({u, 0, 0, (int) adj[u].size() - 1});
}

// find path using bfs
// returns minimum capacity
int find_path(int src, int sink) {
	// init
	front = rear = 0;
	memset(visited, 0, sizeof(visited));
	backvert[src] = -1;
	backvert[sink] = -1;

	// find path using BFS
	visited[src] = true;
	queue[rear++] = src;

	while (rear - front) {
		int cur = queue[front++];

		if (cur == sink) break;

		for (int i = 0; i < adj[cur].size(); i++) {
			Edge edge = adj[cur][i];

			if (visited[edge.dest]) continue;
			if (edge.capacity - edge.flow <= 0) continue;

			visited[edge.dest] = true;
			queue[rear++] = edge.dest;

			backvert[edge.dest] = cur;
			backidx[edge.dest] = i;
		}
	}

	// check the path is found
	if (backvert[sink] == -1) return 0;

	// check minimum possible flow
	int mincap = INF;
	int cur = sink;
	while (backvert[cur] != -1) {
		Edge edge = adj[backvert[cur]][backidx[cur]];
		mincap = min(mincap, edge.capacity - edge.flow);
		cur = backvert[cur];
	}

	// make a flow
	cur = sink;
	while (backvert[cur] != -1) {
		Edge &edge = adj[backvert[cur]][backidx[cur]];

		edge.flow += mincap;
		adj[edge.dest][edge.residual_idx].flow -= mincap;

		cur = backvert[cur];
	}

	return mincap;
}

int main() {
	// read input and make edges by dividing vertex into two parts, (in) and (out).
	int N, P;
	scanf("%d %d", &N, &P);
	for (int p = 0; p < P; p++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(u * 2 + 1, v * 2, 1); // n * 2 = (in), n * 2 + 1 = (out)
		add_edge(v * 2 + 1, u * 2, 1);
	}
	for (int n = 1; n <= N; n++) {
		add_edge(n * 2, n * 2 + 1, 1);
	}

	// do admonds-karp algorithm
	int src = 1 * 2 + 1;
	int sink = 2 * 2;

	int result = 0;
	int flow;
	while ((flow = find_path(src, sink)))
		result += flow;

	// print result
	printf("%d\n", result);

	return 0;
}

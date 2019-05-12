#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int T;

int V, E;
vector<int> adj[20004];

int set[20004];
int visited[20004];

pair<int, int> queue[200005];
int front, rear;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &V, &E);

		for (int v = 1; v <= V; v++) adj[v].clear();
		memset(set, 0, sizeof(set));
		memset(visited, 0, sizeof(visited));
		front = rear = 0;

		for (int e = 1; e <= E; e++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		bool valid = true;

		for (int v = 1; v <= V; v++) {
			if (visited[v]) continue;

			set[v] = 0;
			visited[v] = true;

			for (int next : adj[v]) queue[rear++] = {v, next};

			while (rear - front > 0) {
				pair<int, int> cur = queue[front++];

				if (!visited[cur.second]) {
					set[cur.second] = !set[cur.first];
					visited[cur.second] = true;

					for (int next : adj[cur.second]) {
						if (!visited[next]) {
							queue[rear++] = {cur.second, next};
						}
					}
				} else {
					if (set[cur.first] == set[cur.second]) {
						valid = false;
						break;
					}
				}
			}

			if (!valid) break;
		}

		printf("%s\n", valid ? "YES" : "NO");
	}

	return 0;
}

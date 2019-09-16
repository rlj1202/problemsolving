#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

long long adj[102][102];
long long earns[102];

long long mindist[102];

// bfs
long long queue[102];
bool visited[102];
int front, rear;

int main() {
	int N, A, B, M;
	scanf("%d %d %d %d", &N, &A, &B, &M);
	memset(adj, 0x3f, sizeof(adj));

	for (int m = 0; m < M; m++) {
		int s, d;
		long long cost;
		scanf("%d %d %lld", &s, &d, &cost);
		adj[s][d] = min(adj[s][d], cost);
	}

	for (int n = 0; n < N; n++) {
		scanf("%lld", earns + n);

		for (int m = 0; m < N; m++) {
			if (adj[m][n] != INF)
				adj[m][n] -= earns[n];
		}
	}

	memset(mindist, 0x3f, sizeof(mindist));
	mindist[A] = -earns[A];

	bool gee = false;

	for (int n = 0; n < N; n++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (adj[i][j] == INF) continue;
				if (mindist[i] == INF) continue;

				long long newdist = mindist[i] + adj[i][j];
				if (mindist[j] > newdist) {
					mindist[j] = newdist;

					if (n == N - 1) { // detect negative cycle
						// bfs
						front = rear = 0;
						memset(visited, 0, sizeof(visited));

						queue[rear++] = j;
						visited[j] = true;

						while (rear - front) {
							int cur = queue[front++];

							for (int next = 0; next < N; next++) {
								if (visited[next]) continue;
								if (adj[cur][next] == INF) continue;

								queue[rear++] = next;
								visited[next] = true;
							}
						}

						if (visited[B]) gee = true;
					}
				}
			}
		}
	}

	if (mindist[B] == INF) {
		printf("gg\n");
	} else if (gee) {
		printf("Gee\n");
	} else {
		printf("%lld\n", -mindist[B]);
	}

	return 0;
}

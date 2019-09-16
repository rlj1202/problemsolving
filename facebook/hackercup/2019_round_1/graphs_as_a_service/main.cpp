#include <cstdio>
#include <cstring>

const int INF = 0x3f3f3f3f;

struct Edge { int a, b, cost; };

int adj[52][52];
Edge edges[1003];

int main() {
	int T;

	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int N, M;
		memset(adj, INF, sizeof(adj));

		scanf("%d %d", &N, &M);
		for (int m = 0; m < M; m++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			adj[x][y] = z;
			adj[y][x] = z;
			edges[m] = {x, y, z};
		}

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					int newd = adj[i][k] + adj[k][j];

					if (adj[i][j] > newd)
						adj[i][j] = newd;
				}
			}
		}

		bool impossible = false;

		for (int m = 0; m < M; m++) {
			Edge cur = edges[m];
			if (cur.cost != adj[cur.a][cur.b]) {
				impossible = true;
				break;
			}
		}

		printf("Case #%d: ", t);
		if (!impossible) {
			printf("%d\n", M);
			for (int m = 0; m < M; m++) {
				Edge cur = edges[m];
				printf("%d %d %d\n", cur.a, cur.b, cur.cost);
			}
		} else printf("Impossible\n");
	}

	return 0;
}

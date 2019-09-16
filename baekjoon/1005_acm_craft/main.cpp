#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

int times[1003];
int adj[1003][1003];
int indegrees[1003];
int mintime[1003];

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N, K, W;
		memset(indegrees, 0, sizeof(indegrees));
		memset(adj, 0, sizeof(adj));
		memset(mintime, 0, sizeof(mintime));
		scanf("%d %d", &N, &K);
		for (int n = 1; n <= N; n++) {
			scanf("%d", times + n);
		}
		for (int k = 0; k < K; k++) {
			int x, y;
			scanf("%d %d", &x, &y);
			adj[x][y] = 1;
			indegrees[y]++;
		}
		scanf("%d", &W);

		queue<int> q;

		for (int n = 1; n <= N; n++) {
			if (indegrees[n]) continue;
			q.push(n);
		}

		while (!q.empty()) {
			int curvertices = q.size();
			while (curvertices--) {
				int cur = q.front();
				q.pop();
				for (int next = 1; next <= N; next++) {
					if (!adj[cur][next]) continue;

					mintime[next] = max(mintime[next], mintime[cur] + times[cur]);

					if (--indegrees[next] == 0)
						q.push(next);
				}
			}
		}

		printf("%d\n", mintime[W] + times[W]);
	}

	return 0;
}

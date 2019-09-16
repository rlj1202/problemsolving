#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Point { int r, c; };

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

bool grid[52][52];
bool visited[52][52];

queue<Point> q;

int result;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int M, N, K;
		scanf("%d %d %d", &M, &N, &K);
		memset(grid, 0, sizeof(grid));
		for (int k = 0; k < K; k++) {
			int x, y;
			scanf("%d %d", &x, &y);
			grid[y][x] = 1;
		}

		memset(visited, 0, sizeof(visited));
		result = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (!grid[r][c]) continue;
				if (visited[r][c]) continue;

				visited[r][c] = true;
				q.push({r, c});

				while (!q.empty()) {
					Point cur = q.front(); q.pop();

					for (int i = 0; i < 4; i++) {
						Point next = {cur.r + dr[i], cur.c + dc[i]};
						if (!grid[next.r][next.c]) continue;
						if (visited[next.r][next.c]) continue;

						visited[next.r][next.c] = true;
						q.push(next);
					}
				}

				result++;
			}
		}

		printf("%d\n", result);
	}

	return 0;
}

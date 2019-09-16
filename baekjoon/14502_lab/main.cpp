#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Point {
	int r, c;
};

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int grid[12][12];

int walls;

bool visited[12][12];

int result;

Point getPoint(int index, int width) {
	return {(index - 1) / width + 1, (index - 1) % width + 1};
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			scanf("%d", &grid[r][c]);

			if (grid[r][c] == 1) walls++;
		}
	}

	// iterate all permutation
	for (int i = 1; i <= N * M - 2; i++) {
		Point first = getPoint(i, M);
		if (grid[first.r][first.c] != 0) continue;
		grid[first.r][first.c] = 1;

		for (int j = i + 1; j <= N * M - 1; j++) {
			Point second = getPoint(j, M);
			if (grid[second.r][second.c] != 0) continue;
			grid[second.r][second.c] = 1;

			for (int k = j + 1; k <= N * M; k++) {
				Point third = getPoint(k, M);
				if (grid[third.r][third.c] != 0) continue;
				grid[third.r][third.c] = 1;

				// do bfs
				int virus_count = 0;
				queue<Point> q;
				memset(visited, 0, sizeof(visited));
				for (int r = 1; r <= N; r++) {
					for (int c = 1; c <= M; c++) {
						if (visited[r][c]) continue;
						if (grid[r][c] != 2) continue;

						visited[r][c] = true;
						q.push({r, c});

						while (!q.empty()) {
							Point cur = q.front(); q.pop();
							virus_count++;

							for (int d = 0; d < 4; d++) {
								Point next;
								next.r = cur.r + dr[d];
								next.c = cur.c + dc[d];
								if (next.r < 1 || N < next.r) continue;
								if (next.c < 1 || M < next.c) continue;
								if (grid[next.r][next.c] == 1) continue; // wall
								if (visited[next.r][next.c]) continue;

								visited[next.r][next.c] = true;
								q.push(next);
							}
						}
					}
				}

				int safe_count = N * M - virus_count - walls - 3;
				result = max(result, safe_count);
				// end bfs

				grid[third.r][third.c] = 0;
			}

			grid[second.r][second.c] = 0;
		}

		grid[first.r][first.c] = 0;
	}

	printf("%d\n", result);

	return 0;
}

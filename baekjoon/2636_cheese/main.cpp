#include <iostream>
#include <algorithm>

using namespace std;

static const int AIR = 1;
static const int CHEESE = 2;
static const int SURFACE = 3;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int N, M;
int grid[102][102];

int totalcheese;

int visited[102][102];

pair<int, int> queue[10004];
int qfront, qrear;

pair<int, int> surfaces[10004];
int sfront, srear;

void findsurface(int r, int c) {
	qfront = qrear = 0;
	queue[qrear++] = {r, c};
	visited[r][c] = 1;

	while (qrear - qfront > 0) {
		pair<int, int> cur = queue[qfront++];

		int cheese = 0;

		for (int i = 0; i < 4; i++) {
			pair<int, int> next = {cur.first + dr[i], cur.second + dc[i]};

			if (!visited[next.first][next.second] && grid[next.first][next.second] == AIR) {
				visited[next.first][next.second] = 1;
				queue[qrear++] = next;
			}
			if (grid[next.first][next.second] == CHEESE) cheese++;
		}

		if (cheese > 0) {
			grid[cur.first][cur.second] = SURFACE;
			surfaces[srear++] = {cur.first, cur.second};
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			scanf("%d", &grid[r][c]);
			grid[r][c]++;
			if (grid[r][c] == CHEESE) totalcheese++;
		}
	}

	findsurface(1, 1);

	int remaincheese = totalcheese;

	int phase = 0;
	int lastcheese = 0;

	while (remaincheese > 0) {
		phase++;
		lastcheese = remaincheese;

		int cursurfaces = srear - sfront;

		while (cursurfaces--) {
			pair<int, int> cur = surfaces[sfront++];

			for (int i = 0; i < 4; i++) {
				pair<int, int> next = {cur.first + dr[i], cur.second + dc[i]};

				if (!visited[next.first][next.second] && grid[next.first][next.second] == CHEESE) {
					visited[next.first][next.second] = 1;

					grid[next.first][next.second] = AIR; // melt the cheese-!!!
					remaincheese--;

					findsurface(next.first, next.second);
				}
			}
		}
	}

	printf("%d\n", phase);
	printf("%d\n", lastcheese);

	return 0;
}

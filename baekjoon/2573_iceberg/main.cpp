#include <iostream>
#include <cstring>
#include <list>

using namespace std;

struct Point { int r, c; };

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int N, M;
int grid[302][302];
int icebergs; // number of ice blocks

int airvisited[302][302];

list<Point> surfaces;
int visited[302][302];

Point queue[90004];
int qfront, qrear;

void findsurface(int r, int c) {
	qfront = qrear = 0;
	queue[qrear++] = {r, c};

	airvisited[r][c] = 1;

	while (qrear - qfront > 0) {
		Point cur = queue[qfront++];

		int ices = 0;

		for (int i = 0; i < 4; i++) {
			Point next = {cur.r + dr[i], cur.c + dc[i]};

			// add all air blocks into queue
			if (!airvisited[next.r][next.c] && grid[next.r][next.c] == 0) {
				airvisited[next.r][next.c] = 1;
				queue[qrear++] = next;
			}

			if (grid[next.r][next.c] > 0) ices++;
		}

		// if there are icebergs around air block, regard it as surface and push it to list.
		if (ices > 0) surfaces.push_back(cur);
	}
}

int main() {
	// init
	memset(grid, -1, sizeof(grid));

	// read input
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			scanf("%d", &grid[n][m]);
			if (grid[n][m] > 0) icebergs++;
		}
	}

	// initialize surface
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++)
			if (!airvisited[r][c] && grid[r][c] == 0) findsurface(r, c);

	int phase = 0;

	while (icebergs > 0) {
		// count number of icebergs
		Point surface = *surfaces.begin();
		Point iceberg = {0, 0};
		for (int i = 0; i < 4; i++) {
			Point next = {surface.r + dr[i], surface.c + dc[i]};
			if (grid[next.r][next.c] > 0) {
				iceberg = next;
				break;
			}
		}

		qfront = qrear = 0;
		queue[qrear++] = iceberg;
		memset(visited, 0, sizeof(visited));
		visited[iceberg.r][iceberg.c] = 1;
		int count = 1;
		while (qrear - qfront > 0) {
			Point cur = queue[qfront++];

			for (int i = 0; i < 4; i++) {
				Point next = {cur.r + dr[i], cur.c + dc[i]};
				if (!visited[next.r][next.c] && grid[next.r][next.c] > 0) {
					visited[next.r][next.c] = 1;
					queue[qrear++] = next;
					count++;
				}
			}
		}

		// if counted numbeer of icebergs doesn't match,
		// it means that iceberg is broken into two or more pieces.
		if (count != icebergs) break;

		phase++;

		// melt the icebergs
		for (Point cur : surfaces) {
			for (int i = 0; i < 4; i++) {
				Point next = {cur.r + dr[i], cur.c + dc[i]};
				if (grid[next.r][next.c] > 0)
					if (--grid[next.r][next.c] == 0) icebergs--;
			}
		}

		// update surface
		list<Point>::iterator iter = surfaces.begin();
		while (iter != surfaces.end()) {
			Point cur = *iter;
			int ices = 0;
			for (int i = 0; i < 4; i++) {
				Point next = {cur.r + dr[i], cur.c + dc[i]};
				if (grid[next.r][next.c] > 0) ices++;
				if (!airvisited[next.r][next.c] && grid[next.r][next.c] == 0) {
					airvisited[next.r][next.c] = 1;
					surfaces.push_back(next);
				}
			}
			if (ices == 0) iter = surfaces.erase(iter);
			else iter++;
		}
	}

	// print result
	printf("%d\n", icebergs > 0 ? phase : 0);

	return 0;
}

#include <cstdio>
#include <algorithm>

using namespace std;

int R, C, E, N;

int grid[102][102];
int maxheight[102][102];

void updatemax(int r, int c) {
	if (r < 0 || c < 0 || r > R - 2 || c > C - 2) return;

	maxheight[r][c] = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			maxheight[r][c] = max(maxheight[r][c], grid[r + i][c + j]);
}

int main() {
	scanf("%d %d %d %d", &R, &C, &E, &N);
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			scanf("%d", &grid[r][c]);
		}
	}

	for (int r = 1; r <= R - 2; r++)
		for (int c = 1; c <= C - 2; c++)
			updatemax(r, c);

	for (int n = 0; n < N; n++) {
		int rs, cs, ds;
		scanf("%d %d %d", &rs, &cs, &ds);

		int targetheight = maxheight[rs][cs] - ds;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				grid[rs + i][cs + j] = min(
						grid[rs + i][cs + j], targetheight);

		for (int r = rs - 2; r <= rs + 2; r++)
			for (int c = cs - 2; c <= cs + 2; c++)
				updatemax(r, c);
	}

	int totaldepth = 0;

	for (int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++)
			totaldepth += max(E - grid[r][c], 0);

	printf("%d\n", totaldepth * 72 * 72);

	return 0;
}

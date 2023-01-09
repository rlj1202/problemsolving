#include <stdio.h>
#include <string.h>
#include <math.h>

const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};

const int SIZE = 999;
const int ROOKS = 666;

struct Point { int x, y; };

Point king;
Point rooks[1003];

int grid[1003][1003];

int targetx;
int targety;

int main() {
	// read input
	int x, y;
	scanf("%d %d", &x, &y);
	king = {x, y};

	for (int i = 1; i <= ROOKS; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		rooks[i] = {x, y};

		grid[x][y] = 1;
	}

	// simulate
	targetx = (SIZE + 1) / 2;
	targety = (SIZE + 1) / 2;

	while (true) {
		// white's turn (king)
		int nexti = 0;
		int dist = 0x3f3f3f3f;
		for (int i = 0; i < 8; i++) {
			Point next = {king.x + dx[i], king.y + dy[i]};
			if (grid[next.x][next.y] != 0) continue;
			if (next.x < 1 || SIZE < next.x) continue;
			if (next.y < 1 || SIZE < next.y) continue;

			int xdist = abs(next.x - targetx);
			int ydist = abs(next.y - targety);
			int newdist = xdist*xdist + ydist*ydist;
			if (dist > newdist) {
				dist = newdist;
				nexti = i;
			}
		}
		king.x += dx[nexti];
		king.y += dy[nexti];
		printf("%d %d\n", king.x, king.y);
		fflush(stdout);

		// black's turn (rook)
		int k, x, y;
		scanf("%d %d %d", &k, &x, &y);
		if (k == 0 || x == 0 || y == 0) break;
		if (k == -1 || x == -1 || y == -1) break;

		Point &rook = rooks[k];
		grid[rook.x][rook.y] = 0;

		rook = {x, y};
		grid[rook.x][rook.y] = 1;

		// change the target
		if (king.x == 500 && king.y == 500) {
			int quadrant[2][2];
			memset(quadrant, 0, sizeof(quadrant));
			for (int i = 1; i <= ROOKS; i++) {
				Point rook = rooks[i];
				quadrant[rook.x / 500][rook.y / 500]++;
			}

			int qx = 0, qy = 0;
			int last = 0x3f3f3f3f;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					if (last > quadrant[i][j]) {
						last = quadrant[i][j];
						qx = i;
						qy = j;
					}
				}
			}

			targetx = (1 - qx) * (SIZE - 1) + 1;
			targety = (1 - qy) * (SIZE - 1) + 1;
		}
	}

	return 0;
}

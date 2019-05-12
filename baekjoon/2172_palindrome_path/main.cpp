#include <cstdio>
#include <cstring>

using namespace std;

struct Point {
	int r, c;
	Point operator+ (const Point &o) {
		return {r + o.r, c + o.c};
	}
};

const Point delta[] = {
	{-1, -1},
	{-1, 0},
	{-1, 1},

	{0, -1},
	{0, 1},

	{1, -1},
	{1, 0},
	{1, 1},
};

int grid[22][22];

int dp[22][22][22][22][22]; // dp[len][point][point];

Point getPoint(int index, int width) {
	return {index % width + 1, index / width + 1};
}

int getGrid(Point p) {
	return grid[p.r][p.c];
}

int& getDP(int l, Point a, Point b) {
	return dp[l][a.r][a.c][b.r][b.c];
}

int main() {
	// init
	memset(grid, -1, sizeof(grid));
	
	// read input
	int N, L;
	scanf("%d %d", &N, &L);
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++) scanf("%d", &grid[r][c]);

	// when L = 1
	for (int a = 0; a < N * N; a++) {
		Point A = getPoint(a, N);
		getDP(1, A, A) = 1;
	}

	// when L = 2
	for (int a = 0; a < N * N; a++) {
		Point A = getPoint(a, N);
		for (int i = 0; i < 8; i++) {
			Point B = A + delta[i];

			if (getGrid(A) != getGrid(B)) continue;

			getDP(2, A, B) = 1;
		}
	}

	// when L >= 3
	for (int l = L % 2 == 0 ? 4 : 3; l <= L; l += 2) {
		for (int a = 0; a < N * N; a++) {
			Point A = getPoint(a, N);
			for (int b = a; b < N * N; b++) {
				Point B = getPoint(b, N);

				if (getGrid(A) != getGrid(B)) continue;

				for (int i = 0; i < 8; i++) {
					Point Anxt = A + delta[i];
					for (int j = 0; j < 8; j++) {
						Point Bnxt = B + delta[j];

						if (getGrid(Anxt) != getGrid(Bnxt)) continue;

						getDP(l, A, B) += getDP(l - 2, Anxt, Bnxt);
					}
				}

				getDP(l, B, A) = getDP(l, A, B);
			}
		}
	}

	// print result
	int result = 0;

	for (int a = 0; a < N * N; a++) {
		Point A = getPoint(a, N);
		for (int b = 0; b < N * N; b++) {
			Point B = getPoint(b, N);

			result += getDP(L, A, B);
		}
	}

	printf("%d\n", result);

	return 0;
}

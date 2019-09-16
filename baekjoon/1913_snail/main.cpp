#include <cstdio>

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int grid[1003][1003];

int main() {
	int N, P;
	scanf("%d %d", &N, &P);

	int curr = (N + 1) / 2;
	int curc = (N + 1) / 2;
	int curn = 1;
	int curdir = 0;

	int resultr;
	int resultc;

	for (int i = 0; i < N*N; i++) {
		if (curn == P) {
			resultr = curr;
			resultc = curc;
		}
		grid[curr][curc] = curn++;
		curr += dr[curdir];
		curc += dc[curdir];
		int nextdir = (curdir + 1) % 4;
		if (grid[curr + dr[nextdir]][curc + dc[nextdir]] == 0) {
			curdir = nextdir;
		}
	}

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			printf("%d ", grid[r][c]);
		}
		printf("\n");
	}
	printf("%d %d\n", resultr, resultc);

	return 0;
}

#include <cstdio>

const int dr[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dc[] = {1, 0, -1, 0, 1, 1, -1, -1};

char grid[102][102];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			scanf(" %c", &grid[r][c]);
		}
	}

	bool valid = true;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (grid[r][c] == '*') continue;

			int k;
			if (grid[r][c] == '.') k = 0;
			else k = grid[r][c] - '0';

			int count = 0;

			for (int i = 0; i < 8; i++) {
				char next = grid[r + dr[i]][c + dc[i]];

				if (next == '*') {
					count++;
				}
			}

			if (k != count) {
				valid = false;
				break;
			}
		}
	}

	printf("%s\n", valid ? "YES" : "NO");

	return 0;
}

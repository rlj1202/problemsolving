#include <cstdio>

char grid[82][82];

int main() {
	int C;
	scanf("%d", &C);

	while (C--) {
		int N, M;
		scanf("%d %d", &N, &M);
		for (int n = 1; n <= N; n++) {
			for (int m = 1; m <= M; m++) {
				scanf(" %c", &grid[n][m]);
			}
		}


		printf("%d\n", 0);
	}

	return 0;
}

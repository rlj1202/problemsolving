#include <iostream>

int M, N;
int grid[20][20];

int main() {
	scanf("%d %d", &M, &N);
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			scanf("%d", &grid[m][n]);
		}
	}

	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
			printf("%d", 0);
		}
		printf("\n");
	}

	return 0;
}

#include <iostream>

int N;
int grid[20][20];

int main() {
	scanf("%d", &N);
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			scanf("%d", &grid[r][c]);
		}
	}

	printf("%d\n", 0);

	return 0;
}

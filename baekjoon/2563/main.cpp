#include <cstdio>

int grid[102][102];
int result;

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int x, y;
		scanf("%d %d", &x, &y);

		for (int h = 0; h < 10; h++) {
			grid[x][y + h]++;
			grid[x + 10][y + h]--;
		}
	}

	for (int y = 1; y <= 100; y++) {
		int paper = 0;

		for (int x = 1; x <= 100; x++) {
			paper += grid[x][y];
			if (paper) result++;
		}
	}

	printf("%d\n", result);

	return 0;
}

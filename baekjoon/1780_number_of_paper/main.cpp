#include <cstdio>

int grid[3003][3003];

void recur(int *count, int r, int c, int size) {

}

int main() {
	int N;
	scanf("%d", &N);
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			scanf("%d", &grid[r][c]);

	int count[3];
	recur(count, 0, 0, N);

	for (int i = 0; i < 3; i++) printf("%d\n", count[i]);

	return 0;
}

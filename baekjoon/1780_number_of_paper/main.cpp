#include <cstdio>

int grid[3003][3003];

int recur(int *count, int start_r, int start_c, int size) {
	if (size == 1) {
		count[grid[start_c][start_r] + 1]++;
		return grid[start_c][start_r] + 1;
	}

	int types[3] = {0, 0, 0};
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			int new_size = size / 3;
			int type = recur(count,
				start_r + new_size * r,
				start_c + new_size * c,
				new_size);
			if (type >= 0) types[type]++;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (types[i] == 9) {
			count[i] += 1 - 9;
			return i;
		}
	}

	return -1;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			scanf("%d", &grid[r][c]);

	int count[3] = {0, 0, 0};
	recur(count, 0, 0, N);

	for (int i = 0; i < 3; i++) printf("%d\n", count[i]);

	return 0;
}

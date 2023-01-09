#include <iostream>

int N, M;
long long K;
long long grid[22][22];

long long result;

int f(int mask, int r, int c, int destR, int destC) {
	if (r == destR && c == destC) {
		return ;
	}

	mask ^= grid[r][c];
	int result = 0;
	if (r < destR) result += f(mask, r + 1, c, destR, destC);
	if (c < destC) result += f(mask, r, c + 1, destR, destC);
	return result;
}

int main() {
	// read input
	scanf("%d %d %lld", &N, &M, &K);

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			scanf("%lld", &grid[n][m]);
		}
	}

	int row = 1;
	int col = M;
	while (row <= N && col >= 1) {
		// from start
		int mask = 0;

		
		// from destination
		


		row++;
		col--;
	}

	// print result
	printf("%lld\n", result);

	return 0;
}

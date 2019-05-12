#include <iostream>

int T, N;
int keypad[4][3] = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	{0, -1, -1}
};
int cnt[10];
int adj[10][4];
int dp[10][1003];

int main() {
	scanf("%d", &T);

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			int digit = keypad[y][x];

			if (digit == -1) continue;

			if (x - 1 >= 0 && keypad[y][x - 1] != -1)
				adj[digit][cnt[digit]++] = keypad[y][x - 1];
			if (x + 1 < 3 && keypad[y][x + 1] != -1)
				adj[digit][cnt[digit]++] = keypad[y][x + 1];
			if (y - 1 >= 0 && keypad[y - 1][x] != -1)
				adj[digit][cnt[digit]++] = keypad[y - 1][x];
			if (y + 1 < 4 && keypad[y + 1][x] != -1)
				adj[digit][cnt[digit]++] = keypad[y + 1][x];
		}
	}

	for (int i = 0; i < 10; i++)
		dp[i][1] = 1;

	while (T--) {
		scanf("%d", &N);

		for (int n = 2; n <= N; n++) {
			for (int d = 0; d < 10; d++) {
				dp[d][n] = 0;
				for (int i = 0; i < cnt[d]; i++) {
					dp[d][n] += dp[adj[d][i]][n - 1];
					dp[d][n] %= 1234567;
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += dp[i][N];
			sum %= 1234567;
		}
		printf("%d\n", sum);
	}

	return 0;
}

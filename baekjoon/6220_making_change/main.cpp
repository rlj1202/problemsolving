#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int C, N;
int coins[12];

int dp[12][1003];

int main() {
	scanf("%d %d", &C, &N);
	for (int n = 1; n <= N; n++) scanf("%d", coins + n);
	sort(coins + 1, coins + N + 1);

	memset(dp, INF, sizeof(dp));
	dp[0][0] = 0;
	for (int n = 1; n <= N; n++) {
		int coin = coins[N - n + 1];

		for (int c = 0; c <= C; c++) {
			dp[n][c] = dp[n - 1][c];

			if (c - coin < 0) continue;

			dp[n][c] = min(dp[n][c], dp[n][c - coin] + 1);
			dp[n][c] = min(dp[n][c], dp[n - 1][c - coin] + 1);
		}
	}

	printf("%d\n", dp[N][C]);

	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int grid[1003][1003];

int dp[1003][1003];
int result;

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		char raw[1003];
		scanf("%s", raw);
		for (int m = 1; m <= M; m++)
			grid[n][m] = raw[m - 1] - '0';
	}

	result = 0;

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			if (grid[n][m] == 0) continue;

			dp[n][m] = min(
					dp[n - 1][m - 1],
					min(dp[n - 1][m],
						dp[n][m - 1])
					) + 1;

			result = max(result, dp[n][m]);
		}
	}

	printf("%d\n", result * result);

	return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

int N;
int grid[102][102];

long long dp[102][102];

long long f(int n, int m) {
	if (dp[n][m] != -1) return dp[n][m];

	if (n >= N || m >= N) return 0;
	if (n == N - 1 && m == N - 1) return 1;

	int cur = grid[n][m];

	long long result = 0;
	if (cur != 0) result = f(n + cur, m) + f(n, m + cur);

	return dp[n][m] = result;
}

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++)
		for (int m = 0; m < N; m++)
			scanf("%d", &grid[n][m]);

	memset(dp, -1, sizeof(dp));
	printf("%lld\n", f(0, 0));

	return 0;
}

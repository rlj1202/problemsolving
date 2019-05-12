#include <iostream>

int N;

long long dp[32];

int main() {
	scanf("%d", &N);

	dp[2] = 3;
	for (int n = 4; n <= N; n += 2) {
		dp[n] = 2;
		dp[n] += dp[n - 2] * dp[2];
		for (int m = 2; m <= n - 4; m += 2) {
			dp[n] += dp[m] * 2;
		}
	}

	printf("%lld\n", dp[N]);

	return 0;
}

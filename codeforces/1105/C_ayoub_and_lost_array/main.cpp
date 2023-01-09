#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int N, L, R;

long long dp[200005][3];

long long f(int len, int remainder) {
	if (dp[len][remainder] != -1) return dp[len][remainder];

	long long result = 0;

	for (int i = 0; i < 3; i++) {
		result += (f(1, i) * f(len - 1, (3 - i + remainder) % 3)) % MOD;
	}
	result %= MOD;

	return dp[len][remainder] = result;
}

int main() {
	scanf("%d %d %d", &N, &L, &R);

	memset(dp, -1, sizeof(dp));

	int range = R - L + 1;
	dp[1][0] = range / 3;
	dp[1][1] = range / 3;
	dp[1][2] = range / 3;
	int first_remainder = L % 3;
	for (int i = 0; i < range % 3; i++) dp[1][(i + first_remainder) % 3]++;

	f(N, 0);

	printf("%lld\n", dp[N][0]);

	for (int i = 0; i < 3; i++) {
		for (int n = 1; n <= N; n++) {
			printf("%4d ", dp[n][i]);
		}
		printf("\n");
	}

	return 0;
}

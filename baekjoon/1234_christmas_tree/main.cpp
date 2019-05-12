#include <iostream>
#include <cstring>

using namespace std;

int N;
int R, G, B;

long long dp[12][102][102][102];

long long outcomedp[12][4];

long long outcomes(int n, int d) {
	if (outcomedp[n][d] != -1) return outcomedp[n][d];

	long long result = 1;

	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	for (int i = 1; i <= d; i++) {
		for (int j = 1; j <= n / d; j++) {
			result /= j;
		}
	}

	return outcomedp[n][d] = result;
}

long long f(int n, int r, int g, int b) {
	if (dp[n][r][g][b] != -1) return dp[n][r][g][b];

	if (r < 0 || g < 0 || b < 0) return 0;
	if (n == N + 1) return 1;

	long long result = 0;

	result += f(n + 1, r - n, g, b);
	result += f(n + 1, r, g - n, b);
	result += f(n + 1, r, g, b - n);

	if (n % 2 == 0) {
		int toys = n / 2;

		result += f(n + 1, r - toys, g - toys, b) * outcomes(n, 2);
		result += f(n + 1, r - toys, g, b - toys) * outcomes(n, 2);
		result += f(n + 1, r, g - toys, b - toys) * outcomes(n, 2);
	}

	if (n % 3 == 0) {
		int toys = n / 3;

		result += f(n + 1, r - toys, g - toys, b - toys) * outcomes(n, 3);
	}

	return dp[n][r][g][b] = result;
}

int main() {
	scanf("%d %d %d %d", &N, &R, &G, &B);

	memset(dp, -1, sizeof(dp));
	memset(outcomedp, -1, sizeof(outcomedp));
	printf("%lld\n", f(1, R, G, B));

	return 0;
}

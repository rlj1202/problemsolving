#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int eyes[22];

int dp[22][2][122];

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N, K;
		int sum = 0;

		memset(dp, 0, sizeof(dp));

		scanf("%d %d", &N, &K);
		for (int n = 1; n <= N; n++) {
			scanf("%d", eyes + n);
			sum += eyes[n];
		}

		dp[0][false][0] = 1;

		for (int n = 1; n <= N; n++) {
			for (int k = 1; k <= 6*N; k++) {
				if (k - eyes[n] >= 0) {
					dp[n][false][k] +=
						dp[n - 1][false][k - eyes[n]] * 6 +
						dp[n - 1][true][k - eyes[n]] * 6;
				}

				for (int d = 1; d <= 6; d++) {
					if (k - d >= 0) {
						dp[n][true][k] +=
							dp[n - 1][false][k - d] * 1 +
							dp[n - 1][true][k - d] * 1;
					}
				}
			}
		}

		printf("< #############\n");

		for (int k = 1; k <= 6*N; k++) {
			printf("%3d ", dp[N][false][k]);
		}
		printf("\n");

		for (int k = 1; k <= 6*N; k++) {
			printf("%3d ", dp[N][true][k]);
		}
		printf("\n");

		int a = 0;
		int b = 0;
		for (int k = K; k <= 6*N; k++) {
			a += dp[N][false][k];
			b += dp[N][true][k];
		}
		printf("%d\n", sum);
		printf("%d %d\n", a, b);

		printf("> #############\n");
	}

	return 0;
}

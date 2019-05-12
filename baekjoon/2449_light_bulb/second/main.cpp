#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int lights[202];

int dp[202][202][22];

int main() {
	// init
	memset(dp, INF, sizeof(dp));

	// read input
	int N, K;
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++) {
		scanf("%d", lights + n);
	}

	// calculate
	for (int n = 0; n < N; n++) {
		for (int k = 1; k <= K; k++) {
			if (k != lights[n]) dp[n][n][k] = 1;
			else dp[n][n][k] = 0;
		}
	}
	
	for (int range = 1; range < N; range++) {
		for (int l = 0; l < N - range + 1; l++) {
			int r = l + range - 1;

			for (int k = 1; k <= K; k++) {
				if (l - 1 >= 0) {
					if (lights[l - 1] != k) {
						dp[l - 1][r][lights[l - 1]] =
							min(dp[l - 1][r][lights[l - 1]], dp[l][r][k] + 1);

						dp[l - 1][r][k] =
							min(dp[l - 1][r][k], dp[l][r][k] + 1);
					} else {
						dp[l - 1][r][lights[l - 1]] =
							min(dp[l - 1][r][lights[l - 1]], dp[l][r][k]);
					}
				}

				if (r + 1 < N) {
					if (lights[r + 1] != k) {
						dp[l][r + 1][lights[r + 1]] =
							min(dp[l][r + 1][lights[r + 1]], dp[l][r][k] + 1);

						dp[l][r + 1][k] =
							min(dp[l][r + 1][k], dp[l][r][k] + 1);
					} else {
						dp[l][r + 1][lights[r + 1]] =
							min(dp[l][r + 1][lights[r + 1]], dp[l][r][k]);
					}
				}
			}
		}
	}

	// print result
	int result = INF;
	for (int k = 1; k <= K; k++) {
		result = min(result, dp[0][N - 1][k]);
	}

	printf("%d\n", result);

	return 0;
}

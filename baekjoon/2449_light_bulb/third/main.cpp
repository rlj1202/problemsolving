#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int lights[202];

int dp[202][202];

int main() {
	// init
	memset(dp, INF, sizeof(dp));
	
	// read input
	int N, K;
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++) scanf("%d", lights + n);

	// calculate
	for (int n = 0; n < N; n++) dp[n][n] = 0;

	for (int range = 2; range <= N; range++) {
		for (int l = 0; l < N - range + 1; l++) {
			int r = l + range - 1;

			for (int m = l + 1; m <= r; m++) {
				dp[l][r] = min(
						dp[l][r],
						dp[l][m - 1] + dp[m][r] + (lights[l] != lights[m]));
			}
		}
	}

	// print result
	printf("%d\n", dp[0][N - 1]);

	return 0;
}

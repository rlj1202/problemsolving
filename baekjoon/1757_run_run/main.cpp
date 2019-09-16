#include <cstdio>
#include <algorithm>

using namespace std;

int dist[10004];

int dp[10004][502][2]; // dp[minute][exhausted rate][running?]

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		scanf("%d", dist + n);
	}
	
	dp[0][0][false] = 0;

	for (int n = 1; n <= N; n++) {
		dp[n][0][false] = dp[n - 1][0][false];

		for (int m = 0; m < M; m++) { // rest
			dp[n][m][false] = max(dp[n][m][false], dp[n - 1][m + 1][false]);
			dp[n][m][false] = max(dp[n][m][false], dp[n - 1][m + 1][true]);
		}

		dp[n][1][true] = dp[n - 1][0][false] + dist[n];

		for (int m = 2; m <= M; m++) {
			dp[n][m][true] = max(dp[n][m][true], dp[n - 1][m - 1][true] + dist[n]);
		}
	}

	printf("%d\n", dp[N][0][false]);

	return 0;
}

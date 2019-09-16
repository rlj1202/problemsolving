#include <cstdio>

int N, S, M;
int volumes[102];

bool dp[102][1003];

int main() {
	scanf("%d %d %d", &N, &S, &M);
	for (int n = 1; n <= N; n++) {
		scanf("%d", volumes + n);
	}

	dp[0][S] = true;

	for (int n = 1; n <= N; n++) {
		for (int v = 0; v <= M; v++) {
			if (v - volumes[n] >= 0) dp[n][v] |= dp[n - 1][v - volumes[n]];
			if (v + volumes[n] <= M) dp[n][v] |= dp[n - 1][v + volumes[n]];
		}
	}

	int result = -1;
	for (int v = 0; v <= M; v++)
		if (dp[N][v]) result = v;

	printf("%d\n", result);

	return 0;
}

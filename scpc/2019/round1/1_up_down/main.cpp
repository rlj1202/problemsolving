#include <cstdio>

int dp[1000006];
int sum[1000006];

int getcount(int n) {
	if (n == 1) return 0;
	if (dp[n]) return dp[n];

	int next;
	if (n % 2 == 1) { // odd number
		next = n + 1;
	} else { // even number
		next = n / 2;
	}

	return dp[n] = getcount(next) + 1;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 2; i <= 1000000; i++) {
		getcount(i);
	}
	for (int i = 1; i <= 1000000; i++) {
		sum[i] = dp[i] + sum[i - 1];
	}

	for (int t = 1; t <= T; t++) {
		int N, M;
		scanf("%d %d", &N, &M);

		int result = sum[M] - sum[N - 1];

		printf("Case #%d\n", t);
		printf("%d\n", result);
	}

	return 0;
}

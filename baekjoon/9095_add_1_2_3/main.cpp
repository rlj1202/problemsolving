#include <iostream>

int T;
int N;
int dp[20];

int main() {
	scanf("%d", &T);

	dp[0] = 1;
	for (int i = 0; i <= 11; i++) {
		for (int j = 1; j <= 3 && i - j >= 0; j++) dp[i] += dp[i - j];
	}

	while (T--) {
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}

	return 0;
}

#include <cstdio>

int time[2503];

int dp[2503][2503];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	time[0] = M;
	for (int r = 1; r <= N; r++) {
		scanf("%d", time + r);
		time[r] += time[r - 1];
	}

	printf("%d\n", 0);

	return 0;
}

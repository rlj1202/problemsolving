#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, K;
int cost[302][302];

int dp[302][302];

int f(int index, int remain_counts) {
	if (dp[index][remain_counts] != -1) return dp[index][remain_counts];
	if (index == N) return 0;
	if (remain_counts == 0) return -1;

	int result = -1;
	for (int next = index + 1; next <= N; next++) {
		if (cost[index][next] == 0) continue;

		int nextcost = f(next, remain_counts - 1);
		if (nextcost == -1) continue;

		result = max(result, cost[index][next] + nextcost);
	}

	return dp[index][remain_counts] = result;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int k = 0; k < K; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a >= b) continue;

		cost[a][b] = max(cost[a][b], c);
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(1, M - 1));

	printf("\n");
	for (int m = M; m >= 1; m--) {
		printf("%3d : ", m);
		for (int n = 1; n <= N; n++) {
			printf("%3d ", dp[n][m]);
		}
		printf("\n");
	}

	return 0;
}

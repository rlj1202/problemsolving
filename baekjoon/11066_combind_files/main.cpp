#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T;

int N;
int costSum[502];

int minCost[502][502];

int dp(int l, int r) {
	if (l == r) return 0;
	if (minCost[l][r] != 0) return minCost[l][r];

	int result = (1 << 30) - 1;

	int cost = costSum[r] - costSum[l - 1];

	for (int m = l; m < r; m++) {
		result = min(result, cost + dp(l, m) + dp(m + 1, r));
	}

	return (minCost[l][r] = result);
}

int main() {
	scanf("%d", &T);

	while (T--) {
		memset(costSum, 0, sizeof(costSum));
		memset(minCost, 0, sizeof(minCost));

		scanf("%d", &N);

		for (int n = 1; n <= N; n++) {
			int value;
			scanf("%d", &value);
			costSum[n] = costSum[n - 1] + value;
		}

		printf("%d\n", dp(1, N));
	}

	return 0;
}

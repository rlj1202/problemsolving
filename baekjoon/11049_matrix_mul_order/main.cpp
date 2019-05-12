#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int N;
int matrices[502];

int minCost[502][502];

int dp(int l, int r) {
	if (minCost[l][r] != 0) return minCost[l][r];

	if (l == r) return 0;
	if (r - l == 1) return minCost[l][r] = matrices[l] * matrices[r] * matrices[r + 1];

	int result = 2000000009;

	for (int m = l + 1; m <= r; m++) {
		int cost = matrices[l] * matrices[m] * matrices[r+1];

		cost += dp(l, m-1);
		cost += dp(m, r);

		result = min(result, cost);
	}

	return minCost[l][r] = result;
}

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++)
		scanf("%d %d", matrices + n, matrices + n + 1);

	printf("%d\n", dp(1, N));

	return 0;
}

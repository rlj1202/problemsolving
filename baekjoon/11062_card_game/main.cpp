#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T;

int N;
int sum[1003];

int minCost[2][1003][1003];

int dp(int person, int l, int r) {
	int maxPoint = sum[r] - sum[l - 1];

	if (l == r) return maxPoint;
	if (minCost[person][l][r] != 0) return minCost[person][l][r];

	int result = max(
			maxPoint - dp(!person, l + 1, r),
			maxPoint - dp(!person, l, r - 1)
			);

	return minCost[person][l][r] = result;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		memset(minCost, 0, sizeof(minCost));

		scanf("%d", &N);

		for (int n = 1; n <= N; n++) {
			int value;
			scanf("%d", &value);
			sum[n] = value + sum[n - 1];
		}

		printf("%d\n", dp(0, 1, N));
	}

	return 0;
}

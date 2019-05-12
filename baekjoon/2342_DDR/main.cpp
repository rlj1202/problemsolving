#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int cost[5][5] = {
	0, 2, 2, 2, 2,
	0, 1, 3, 4, 3,
	0, 3, 1, 3, 4,
	0, 4, 3, 1, 3,
	0, 3, 4, 3, 1,
};

int arr[100005];
int arrlen;

int dp[5][5][100005];

int f(int l, int r, int nextidx) {
	if (dp[l][r][nextidx] != -1) return dp[l][r][nextidx];
	if (nextidx == arrlen) return 0;

	int result;
	if (l == arr[nextidx] || r == arr[nextidx]) {
		result = 1 + f(l, r, nextidx + 1);
	} else {
		result = 0x3f3f3f3f;

		result = min(result,
				f(arr[nextidx], r, nextidx + 1)
				+ cost[l][arr[nextidx]]
				);
		result = min(result,
				f(l, arr[nextidx], nextidx + 1)
				+ cost[r][arr[nextidx]]
				);
	}

	return dp[l][r][nextidx] = result;
}

int main() {
	while (true) {
		int value;
		scanf("%d", &value);
		if (value == 0) break;
		arr[arrlen++] = value;
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(0, 0, 0));

	return 0;
}

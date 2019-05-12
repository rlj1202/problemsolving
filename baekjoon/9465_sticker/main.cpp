#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T;

int N;
int grid[2][100005];

int dp[100005][3];

int f(int index, int flag) {
	if (dp[index][flag] != -1) return dp[index][flag];
	if (index == N) return 0;

	int result = f(index + 1, 0);
	if (flag != 1) result = max(result, f(index + 1, 1) + grid[0][index + 1]);
	if (flag != 2) result = max(result, f(index + 1, 2) + grid[1][index + 1]);

	return dp[index][flag] = result;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		for (int r = 0; r < 2; r++) {
			for (int c = 1; c <= N; c++)
				scanf("%d", &grid[r][c]);
		}

		memset(dp, -1, sizeof(dp));
		printf("%d\n", f(0, 0));
	}

	return 0;
}

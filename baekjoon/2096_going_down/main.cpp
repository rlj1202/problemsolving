#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
char grid[100005][5];

int dp[100005][5];

int get_max(int r, int c) {
	if (dp[r][c] != -1) return dp[r][c];

	if (c < 1 || 3 < c) return 0;
	if (r == N) return grid[r][c];

	int result = 0;
	for (int i = -1; i <= 1; i++) {
		result = max(result, get_max(r + 1, c + i));
	}

	return dp[r][c] = grid[r][c] + result;
}

int get_min(int r, int c) {
	if (dp[r][c] != -1) return dp[r][c];
	
	if (c < 1 || 3 < c) return 0x3f3f3f3f;
	if (r == N) return grid[r][c];

	int result = 0x3f3f3f3f;
	for (int i = -1; i <= 1; i++) {
		result = min(result, get_min(r + 1, c + i));
	}

	return dp[r][c] = grid[r][c] + result;
}

int main() {
	scanf("%d", &N);
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= 3; c++)
			scanf("%d", &grid[r][c]);

	int max_result = 0;
	int min_result = 0x3f3f3f3f;

	memset(dp, -1, sizeof(dp));
	for (int c = 1; c <= 3; c++) {
		max_result = max(max_result, get_max(1, c));
	}

	memset(dp, -1, sizeof(dp));
	for (int c = 1; c <= 3; c++) {
		min_result = min(min_result, get_min(1, c));
	}

	printf("%d %d\n", max_result, min_result);

	return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, K;
int lights[202];
int lightslen;

int dp[202][202][22];

int f(int l, int r, int color) {
	if (dp[l][r][color] != -1) return dp[l][r][color];

	if (l == r) return lights[l] != color;

	int result = INF;

	for (int m = l; m <= r - 1; m++) {
		int a = lights[m];
		int b = lights[m + 1];
		int next = f(l, m, a) + f(m + 1, r, b) + 1;
		if (a != color && b != color) next++;

		result = min(result, next);
	}

	printf("%d %d %d = %d\n", l, r, color, result);

	return dp[l][r][color] = result;
}

int main() {
	scanf("%d %d", &N, &K);
	int prev = 0;
	for (int n = 0; n < N; n++) {
		int color;
		scanf("%d", &color);
		
		if (prev != color) lights[lightslen++] = color;
		prev = color;
	}

	memset(dp, -1, sizeof(dp));

	for (int l = 0; l < lightslen; l++) printf("%d ", lights[l]);
	printf("\n");

	int result = INF;
	for (int k = 1; k <= K; k++) result = min(result, f(0, lightslen - 1, k));
	printf("%d\n", result);

	return 0;
}

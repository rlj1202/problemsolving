#include <iostream>
#include <cstring>

using namespace std;

int dp[12][12];

int f(int h, int w) {
	if (dp[h][w] != -1) return dp[h][w];

	int result = 0;

	for (int m = 1; m < h; m++) {
		result += f(m, w) * f(h - m, w);
	}
	for (int m = 1; m < w; m++) {
		result += f(h, m) * f(h, w - m);
	}

	return dp[h][w] = result;
}

int main() {
	memset(dp, -1, sizeof(dp));

	dp[1][1] = 0;
	dp[1][2] = 1;
	dp[2][1] = 1;

	while (true) {
		int h, w;
		scanf("%d %d", &h, &w);
		if (h == 0 && w == 0) break;

		printf("\t%d\n", f(h, w));
	}

	return 0;
}

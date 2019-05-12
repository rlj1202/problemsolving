#include <iostream>
#include <cstring>

using namespace std;

int N;
int triangle[502][502];

int dp[502][502];

int f(int n, int m) {
	if (dp[n][m] != -1) return dp[n][m];

	if (n == N - 1) {
		return triangle[n][m];
	} else {
		int cur = triangle[n][m];
		int l = f(n + 1, m);
		int r = f(n + 1, m + 1);

		return dp[n][m] = max(cur + l, cur + r);
	}
}

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++)
		for (int m = 0; m < n + 1; m++)
			scanf("%d", &triangle[n][m]);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(0, 0));

	return 0;
}

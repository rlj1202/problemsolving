#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, M;
int arr[102];

int dp[52][102];

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) scanf("%d", arr + n);

	for (int m = 1; m <= M; m++) {
		int prevlimit = (m - 2) * 2 + 1;
		int limit = (m - 1) * 2 + 1;

		for (int n = limit; n <= N; n++) {
			int cur = arr[n];

			dp[m][n] = cur;

			if (m > 1) {
				int prev = -INF;
				for (int l = prevlimit; l <= n - 2; l++)
					prev = max(prev, dp[m - 1][l]);

				dp[m][n] += prev;
			}

			if (n - 1 >= limit) {
				dp[m][n] = max(dp[m][n], dp[m][n - 1] + cur);
			}
		}
	}

	int result = -INF;
	for (int n = (M - 1) * 2 + 1; n <= N; n++) {
		result = max(result, dp[M][n]);
	}
	printf("%d\n", result);

	return 0;
}

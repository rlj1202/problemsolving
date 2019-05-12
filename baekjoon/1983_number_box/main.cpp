#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[2][402];
int zeros[2];

int dp[402][402][402];

int main() {
	scanf("%d", &N);
	for (int r = 0; r < 2; r++) {
		int zero = 0;
		for (int n = 1; n <= N; n++) {
			int cur;
			scanf("%d", &cur);

			if (cur == 0) zero++;
			else arr[r][n - zero] = cur;
		}
		zeros[r] = zero;
	}

	for (int n = 1; n <= N; n++) {
		for (int i = max(1, n - zeros[0]); i <= min(n, N - zeros[0]); i++) {
			for (int j = max(1, n - zeros[1]); j <= min(n, N - zeros[1]); j++) {
				int prevmax = dp[n - 1][i - 1][j - 1] + arr[0][i]*arr[1][j];
				if (j > 1) prevmax = max(prevmax, dp[n - 1][i][j - 1]);
				if (i > 1) prevmax = max(prevmax, dp[n - 1][i - 1][j]);

				dp[n][i][j] = prevmax;

				printf("%d, %d %d = %d \t\t %d %d\n", n, i, j, dp[n][i][j],
						dp[n - 1][i][j - 1], dp[n - 1][i - 1][j]);
			}
		}
	}

	printf("%d\n", dp[N][N - zeros[0]][N - zeros[1]]);

	return 0;
}

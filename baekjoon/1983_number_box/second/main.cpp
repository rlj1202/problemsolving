#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[2][402];
int len[2];

int dp[402][402][402];

int main() {
	scanf("%d", &N);
	for (int r = 0; r < 2; r++) {
		for (int c = 0; c < N; c++) {
			int value;
			scanf("%d", &value);
			if (value != 0) arr[r][++len[r]] = value;
		}
	}

	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= min(len[0], n); i++) {
			for (int j = 1; j <= min(len[1], n); j++) {
				dp[n][i][j] = dp[n - 1][i - 1][j - 1] + arr[0][i]*arr[1][j];

				if (i + 1 <= n)
					dp[n][i][j] = max(dp[n][i][j], dp[n - 1][i][j - 1]);
				if (j + 1 <= n)
					dp[n][i][j] = max(dp[n][i][j], dp[n - 1][i - 1][j]);
			}
		}
	}

	printf("%d\n", dp[N][len[0]][len[1]]);

	return 0;
}

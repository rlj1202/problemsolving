#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int profits[22][302];

int dp[22][302];
int back[22][302];

int main() {
	// read input
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		int amount;
		scanf("%d", &amount);

		for (int m = 0; m < M; m++) {
			int profit;
			scanf("%d", &profit);

			profits[m][amount] = profit;
		}
	}

	// dp
	for (int n = 1; n <= N; n++) {
		dp[0][n] = profits[0][n];
		back[0][n] = n;
	}
	for (int m = 1; m < M; m++) {
		for (int n = 1; n <= N; n++) {
			for (int k = 0; k <= n; k++) {
				int newprofit = profits[m][k] + dp[m - 1][n - k];
				
				if (dp[m][n] < newprofit) {
					dp[m][n] = newprofit;
					back[m][n] = k;
				}
			}
		}
	}

	// print result
	printf("%d\n", dp[M - 1][N]);
	int result[22];
	int remains = N;
	for (int m = M - 1; m >= 0; m--) {
		int amount = back[m][remains];
		result[m] = amount;
		remains -= amount;
	}
	for (int m = 0; m < M; m++) printf("%d ", result[m]);
	printf("\n");

	return 0;
}

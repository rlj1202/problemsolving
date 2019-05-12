#include <iostream>
#include <algorithm>

using namespace std;

int N;
int grid[10][10];
int dp[10][10];

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= N; m++) {
			char value;
			char suit;
			scanf(" %c%c", &value, &suit);

			int point;
			if ('2' <= value && value <= '9') point = value - '0';
			else {
				if (value == 'A') point = 1;
				else if (value == 'T') point = 10;
				else if (value == 'J') point = 11;
				else if (value == 'Q') point = 12;
				else point = 13;
			}
			grid[n][m] = point;
		}
	}

	for (int n = N; n >= 1; n--) {
		for (int m = 1; m <= N; m++) {
			dp[n][m] = grid[n][m] + max(dp[n + 1][m], dp[n][m - 1]);
		}
	}

	printf("%d\n", dp[1][N]);

	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int quntity[10004];

int dp[10004][3];

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++)
		scanf("%d", quntity + n);

	for (int k = 0; k < 3; k++) {
		dp[N + 1][k] = 0;
	}

	for (int n = N; n >= 0; n--) {
		for (int k = 0; k < 2; k++) {
			dp[n][k] = max(dp[n + 1][k + 1] + quntity[n], dp[n + 1][0]);
		}
		dp[n][2] = dp[n + 1][0];
	}

	printf("%d\n", dp[0][0]);

	return 0;
}

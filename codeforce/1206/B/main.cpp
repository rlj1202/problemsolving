#include <cstdio>
#include <algorithm>

using namespace std;

const int NEGATIVE = 0;
const int POSITIVE = 1;

int arr[100005];

long long dp[100005][2];

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", arr + n);
	}
	
	dp[0][NEGATIVE] = abs((-1) - arr[0]);
	dp[0][POSITIVE] = abs((1) - arr[0]);

	for (int n = 1; n < N; n++) {
		dp[n][NEGATIVE] = min(
				abs((-1) - arr[n]) + dp[n - 1][POSITIVE],
				abs((1) - arr[n]) + dp[n - 1][NEGATIVE]);
		dp[n][POSITIVE] = min(
				abs((1) - arr[n]) + dp[n - 1][POSITIVE],
				abs((-1) - arr[n]) + dp[n - 1][NEGATIVE]);
	}

	printf("%lld\n", dp[N - 1][POSITIVE]);

	return 0;
}

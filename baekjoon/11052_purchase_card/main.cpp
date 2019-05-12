#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cost[1003];

int dp[1003];

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		scanf("%d", cost + n);
	}

	for (int n = 1; n <= N; n++) {
		for (int i = n; i <= N; i++) {
			dp[i] = max(dp[i], dp[i - n] + cost[n]);
		}
	}

	printf("%d\n", dp[N]);

	return 0;
}

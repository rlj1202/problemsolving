#include <iostream>
#include <algorithm>

using namespace std;

int N;
int points[302];

int dp[302]; // dp[n] : n 까지 봤을때의 최선

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++)
		scanf("%d", points + n);

	dp[1] = points[1];
	dp[2] = points[1] + points[2];
	dp[3] = max(points[1], points[2]) + points[3];

	for (int n = 4; n <= N; n++) {
		dp[n] = max(dp[n - 2], points[n - 1] + dp[n - 3]) + points[n];
	}

	printf("%d\n", dp[N]);

	return 0;
}
